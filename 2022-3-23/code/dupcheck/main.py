import subprocess
from typing import Final
import re


def shell(command):
    try:
        return subprocess.check_output(command, shell=True, stderr=subprocess.STDOUT).stdout
    except subprocess.CalledProcessError as exc:
        return exc.output


def lcs(s1, s2):
    f = [[0] * len(s1) * 2] * len(s2) * 2

    for i in range(1, len(s1) + 1):
        for j in range(1, len(s2) + 1):
            if s1[i - 1] == s2[j - 1]:
                f[i][j] = 1 + f[i - 1][j - 1]
            else:
                f[i][j] = max(f[i - 1][j], f[i][j - 1])

    return f[len(s1)][len(s2)]


ast1 = str(shell(['clang -cc1 -ast-dump test1.c']))
ast2 = str(shell(['clang -cc1 -ast-dump test2.c']))

elems1 = list([i[0] if i[0] != '' else i[1] for i in
               re.findall(r'([a-zA-Z\_][0-9a-zA-Z\_]*Expr)|([a-zA-Z\_][0-9a-zA-Z\_]*Stmt)', ast1)])
elems2 = list([i[0] if i[0] != '' else i[1] for i in
               re.findall(r'([a-zA-Z\_][0-9a-zA-Z\_]*Expr)|([a-zA-Z\_][0-9a-zA-Z\_]*Stmt)', ast2)])

print(lcs(elems1, elems2) / max(len(elems1), len(elems2)))
