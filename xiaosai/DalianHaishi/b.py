n = int(input())
s = input()
if "domserver" in s and "judgehost" in s:
    print("Domjudge")
elif "domserver" in s:
    print("domserver")
elif "judgehost" in s:
    print("judgehost")
if "Contest Data Server" in s:
    print("cds")