from pyautogui import *

from time import sleep

n = int(input())

sleep(2)

for i in range(n):
    for j in range(i+1):
        write('#')
    press('enter')
