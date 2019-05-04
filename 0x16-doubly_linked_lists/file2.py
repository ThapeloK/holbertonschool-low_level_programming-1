def palindrome():
   for i in range(999, 99, -1):
       for j in range(999, i - 100, -1):
           print(i * j, i, j)
           if (str(i * j) == str(i * j)[::-1]):
               #print(i * j)
               return i * j
print(palindrome())
