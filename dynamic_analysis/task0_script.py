from z3 import *

# Initialize Z3 solver
solver = Solver()

# Define variables for each character in the core flag (24 characters)
core_flag = [BitVec(f'char_{i}', 8) for i in range(24)]

# Define allowed characters (A-Z, a-z, 0-9, and special characters)
allowed_chars = (
    [ord(c) for c in "ABCDEFGHIJKLMNOPQRSTUVWXYZ"] +  # A-Z
    [ord(c) for c in "abcdefghijklmnopqrstuvwxyz"] +  # a-z
    [ord(c) for c in "0123456789"] +                 # 0-9
    [ord(c) for c in "_-{}?!@#"]                     # Special characters
)

# Add constraints for each character to be in the allowed set
for char in core_flag:
    solver.add(Or([char == c for c in allowed_chars]))

# Add constraints for specific parts of the flag (if known)
# For example, if we suspect the flag contains "z3" and "angr":
solver.add(core_flag[10] == ord('z'))  # 11th character is 'z'
solver.add(core_flag[11] == ord('3'))  # 12th character is '3'
solver.add(core_flag[15] == ord('a'))  # 16th character is 'a'
solver.add(core_flag[16] == ord('n'))  # 17th character is 'n'
solver.add(core_flag[17] == ord('g'))  # 18th character is 'g'
solver.add(core_flag[18] == ord('r'))  # 19th character is 'r'

# Initialize variables used in the constraints
local_54 = BitVecVal(0, 32)
local_50 = BitVecVal(1, 32)
local_4c = BitVecVal(0, 32)
local_48 = BitVecVal(1, 32)

# Apply constraints for each character
for i in range(24):
    char = core_flag[i]
    local_54 = local_54 + (i + 1) * ZeroExt(24, char) * (i + 2) % 0x100
    local_50 = (ZeroExt(24, char) + i * 7 + 0x1f) % 0x7b * local_50
    local_4c = local_4c + ((i + 1) * ZeroExt(24, char) + i * i) % 0x200
    local_48 = local_48 ^ ((i + 3) * ZeroExt(24, char) + 0x11) % 0x400

# Final validation constraint
final_expr = (((local_54 * local_50 +
               (((local_4c + local_54 * local_50) - local_48 ^ 0xdeadbeef) & 0xffffff)) -
              local_4c * local_48) + 0xcafebabe) % 0xf1206 == 0xae44

solver.add(final_expr)

# Check if the solver can find a satisfying assignment
if solver.check() == sat:
    model = solver.model()
    flag_core = ''.join([chr(model[char].as_long()) for char in core_flag])
    flag = f"Holberton{{{flag_core}}}"
    print(f"Found flag: {flag}")
else:
    print("No solution found.")
