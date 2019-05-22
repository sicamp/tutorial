s = open('cipher.in').read().strip()

if len(s) == 0 or len(s) > 10 ** 5:
  raise Exception('invalid length')

s = s[::-1]
out = open('cipher.out', 'w')
for a in s:
  if '0' <= a and a <= '9':
    out.write(a)
  else:
    if (a < 'a' or a > 'z') and (a < 'A' or a > 'Z'):
      raise Exception('invalid symbol')
    out.write("'%d'" % ord(a))
out.close()
