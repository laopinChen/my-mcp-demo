from decimal import * # 滙入decimal所有內容

getcontext().prec = 4   # 設精確度為8
print(getcontext().rounding)

num1, num2 = Decimal(2.3582), Decimal(0.6693)
num3 = Decimal(2.3482)
print('接近偶數，進位 num1 + num2 =', num1 + num2)
print('捨位 num3 + num2 =', num3 + num2)

#重設捨去模式, 無條件捨去
getcontext().rounding = ROUND_DOWN
print('無條件捨位 num1 + num2 =', num1 + num2)

#重設捨去模式, 無條件進位
getcontext().rounding = ROUND_UP
print('無條件進位 num1 + num2 =', num1 + num2)

#重設捨去模式, 捨去最後位數，依0或5進位
getcontext().rounding = ROUND_05UP
print('有條件進位 -> 2.352 + 0.1187 = ', end = '')
print(Decimal(2.352) + Decimal(0.1187))
print('有條件進位 -> 2.352 + 0.1137 = ', end = '')
print(Decimal(2.352) + Decimal(0.1137))
print('有條件進位 -> 2.352 + 0.1127 = ', end = '')
print(Decimal(2.352) + Decimal(0.1127))