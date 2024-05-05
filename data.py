from random import randint


a = "123 123 123"
list = """1. Smartphone
2. Laptop
3. Television
4. Headphones
5. Camera
6. Smartwatch
7. Bluetooth speaker
8. Gaming console
9. Tablet
10. Fitness tracker
11. Wireless earbuds
12. Drone
13. Printer
14. External hard drive
15. Bluetooth headphones
16. Virtual reality headset
17. Portable charger
18. Action camera
19. Home security system
20. E-reader
21. Smart home hub
22. Wireless mouse
23. Gaming keyboard
24. Portable projector
25. Robot vacuum cleaner
26. Soundbar
27. Smart thermostat
28. Wireless router
29. Gaming headset
30. Bluetooth keyboard
31. Smart lock
32. Wireless charging pad
33. Electric toothbrush
34. Smart scale
35. Air purifier
36. Smart light bulbs
37. Instant camera
38. Coffee maker
39. Bluetooth car kit
40. Portable Bluetooth keyboard
41. Noise-canceling headphones
42. Fitness smartwatch
43. Smart home security camera
44. Wireless gaming mouse
45. Bluetooth gaming controller
46. Portable DVD player
47. Bluetooth FM transmitter
48. Wireless earphones with mic
49. Smart mirror
50. Solar power bank"""

for i in range(len(list)):
    if list[i] == " ":
        list[i] = list[i].replace(" ","_")

list = list.split("\n")
for i in range(9,len(list)):
    list[i]=list[i][4:]
for i in range(9):
    list[i]=list[i][3:]

for i in range(len(list)):
    print(list[i], randint(100000000,999999999), randint(100,99999))
