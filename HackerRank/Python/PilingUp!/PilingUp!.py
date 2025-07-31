# Enter your code here. Read input from STDIN. Print output to STDOUT
def can_stack(blocks):
    left = 0
    right = len(blocks) - 1
    top = float('inf') 

    while left <= right:
        if blocks[left] >= blocks[right]:
            pick = blocks[left]
            left += 1
        else:
            pick = blocks[right]
            right -= 1

        if pick > top:
            return "No"
        top = pick  

    return "Yes"

t = int(input())
for _ in range(t):
    n = int(input())
    blocks = list(map(int, input().split()))
    print(can_stack(blocks))
