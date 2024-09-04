sx, sy = map(int, input().split())
gx, gy = map(int, input().split())
if sx>gx:
  sx, gx = gx, sx
  sy, gy = gy, sy

if (sx+sy)%2==1:
  sx -= 1
if (gx+gy)%2==1:
  gx -= 1
dif = abs(sx-gx)
#print(sx, gx)
h = abs(gy-sy) 
ans = h + max(dif, h)
print(ans//2)