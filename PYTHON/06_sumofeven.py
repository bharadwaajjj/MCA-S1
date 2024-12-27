# Sum of first 100 even numbers

n=100
sum = n * (n+1)
print("Sum of first 100 Even Numbers is",sum)

# first n even numbers are 2, 4, 6, 8,...
# so sum of first n even numbers will be  2 + 4 + 6 +...+ n
#    so, it can be represented as  2(1 + 2 + 3 +... + n)   --- (1)
#     we know 1 + 2 + 3 + 4 + ... + n is n(n+1) / 2
#       so, from (1) we can write it as  n(n+1)