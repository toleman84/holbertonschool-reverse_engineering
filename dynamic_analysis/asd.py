# Definimos las funciones en Python
def funcOne(param_1, param_2, param_3):
    return param_3 * param_1 - 100 + param_2 * param_1 * 0x3eb + param_3 * 0xd

def funcTwo(param_1, param_2, param_3):
    return param_2 * param_1 + ((param_3 * param_1 - 0x491e + param_2 * 0x65) - (param_2 + param_1 + 0x89))

def funcThree(param_1, param_2):
    temp = param_2 + (((param_2 * 0x1b >> 8) >> 1) - (param_2 >> 7))
    return (temp * -0x13) + param_1 * param_2

def funcFour(param_1, param_2, param_3):
    return param_1 * param_2 * param_3 - param_3 * param_2

def funcFive(param_1, param_2, param_3):
    return (param_1 + param_3 * param_2) % 10000

def funcSix(param_1, param_2, param_3):
    return (param_1 * param_2 + param_3) - param_3 * param_2

def funcSeven(param_1, param_2, param_3):
    return (param_1 * param_2 + param_3 * param_3) - param_3

def funcEight(param_1, param_2, param_3):
    return param_1 * param_2 * param_3 - param_3 * param_2

def funcNine(param_1, param_2, param_3):
    return param_1 + (param_1 * param_2 - param_2 * param_3) - 100

def funcTen(param_1, param_2, param_3):
    return param_2 + param_3 * (param_1 + param_2) - 10000

def funcEleven(param_1, param_2, param_3):
    return param_1 * param_2 + param_3 * param_1 * param_2 - 0x539

def funcTwelve(param_1, param_2, param_3):
    return (param_1 * param_3 + param_2 * 10) - param_1 + 0x89

def funcThirteen(param_1, param_2, param_3):
    return (param_3 * param_1 * param_2) % 10000 - 500

def funcFourteen(param_1, param_2, param_3):
    return param_3 + (param_1 * param_2 * param_3 - param_2 * param_1)

def funcFifteen(param_1, param_2, param_3):
    return (param_3 + param_1 + param_2) * 0x539 - param_3

def funcSixteen(param_1, param_2, param_3):
    return (param_1 * param_2 + param_3 * 10) - param_3 * param_1 + 500

def funcSeventeen(param_1, param_2, param_3):
    return param_3 * 0x65 + (param_1 * param_2 - param_2 * param_3)

def funcEighteen(param_1, param_2, param_3):
    return param_1 * 0x89 + (param_1 * param_2 * param_3 - param_3 * param_2)

def funcNineteen(param_1, param_2, param_3):
    return (param_1 + param_2 + param_3 * 0x89) - param_2 * param_3

def funcTwenty(param_1, param_2, param_3):
    return (param_1 * param_2 + param_3 * param_3) - param_3 * param_1


# Valores esperados de las funciones
expected_values = {
    "funcOne": 0x7a73e0,
    "funcTwo": 0x396c,
    "funcThree": 0x295b,
    "funcFour": 0x110aba,
    "funcFive": 0xcfd,
    "funcSix": 0x1cb,
    "funcSeven": 0x6122,
    "funcEight": 0x16b5ac,
    "funcNine": 0x5ce,
    "funcTen": 0x2d0f,
    "funcEleven": 0x10ce2f,
    "funcTwelve": 0x2c6f,
    "funcThirteen": 0x133d,
    "funcFourteen": 0xee949,
    "funcFifteen": 0x64d5a,
    "funcSixteen": 0xc6c,
    "funcSeventeen": 0x2d63,
    "funcEighteen": 0x105869,
    "funcNineteen": 0x13b1,
    "funcTwenty": 0x319d,
}


# Función para encontrar los caracteres desconocidos
def find_characters(func, expected, known_params, unknown_indices):
    for c1 in range(32, 127):  # Caracteres ASCII imprimibles
        for c2 in range(32, 127):
            params = list(known_params)
            for i, idx in enumerate(unknown_indices):
                params[idx] = c1 if i == 0 else c2
            result = func(*params)
            if result == expected:
                return params
    return None


# Conocemos los primeros caracteres de la flag: "Holberton{"
flag = list("Holberton{")
unknown_indices = list(range(len(flag), 30))  # Asumimos una longitud máxima de 30 caracteres

# Resolvemos cada función en orden
for func_name, expected in expected_values.items():
    func = globals()[func_name]
    known_params = [ord(c) if i < len(flag) else None for i, c in enumerate(flag)]
    unknown_indices = [i for i, v in enumerate(known_params) if v is None]
    
    if unknown_indices:
        result = find_characters(func, expected, known_params, unknown_indices)
        if result:
            for i, c in enumerate(result):
                if known_params[i] is None:
                    flag.append(chr(c))
                    known_params[i] = c
            print(f"Resuelto {func_name}: {''.join(flag)}")
        else:
            print(f"No se pudo resolver {func_name}")
    else:
        print(f"Todos los parámetros para {func_name} son conocidos")

# Imprimimos la flag completa
print(f"Flag completa: {''.join(flag)}")