import cv2
import numpy as np
from pygame.draw import circle

'''_______ИЗОБРАЖЕНИЕ 1_______'''

image = cv2.imread('images/balloon1.jpg')#считываем изображение

hsv_min = np.array((15, 100, 100), np.uint8)
hsv_max = np.array((40, 255, 255), np.uint8)

hsv = cv2.cvtColor(image, cv2.COLOR_BGR2HSV)



thresh = cv2.inRange(hsv, hsv_min, hsv_max)#получаем нашу маску изображение вырезанное по жёлтому

ys, xs = np.nonzero(thresh)
M = cv2.moments(thresh)#смотрим моменты в чб изображении
center = (int(M["m10"] / M["m00"]), int(M["m01"] / M["m00"]))#центр окружности
radius = int(np.sqrt((xs - center[0])**2 + (ys - center[1])**2).max())#радиус
cv2.circle(image, (center[0], center[1]), radius, (0, 255, 0), 2)
cv2.circle(image, (center[0], center[1]), 3, (0, 255, 0), -1)


cv2.imshow('Original', image)
#cv2.imshow("thresh.jpg", thresh)

'''_______ИЗОБРАЖЕНИЕ 2_______'''

image_2 = cv2.imread('images/red.jpg')
resize = cv2.resize(image_2, (600, 600))

hsv_min_2 = np.array((160, 50, 30), np.uint8)
hsv_max_2 = np.array((180, 255, 255), np.uint8)

hsv_2 = cv2.cvtColor(resize, cv2.COLOR_BGR2HSV )
thresh_2  = cv2.inRange(hsv_2, hsv_min_2, hsv_max_2)#получаем нашу маску

ys_2, xs_2 = np.nonzero(thresh_2)
M_2 = cv2.moments(thresh_2)#смотрим моменты в чб изображении
center_2 = (int(M_2["m10"] / M_2["m00"]), int(M_2["m01"] / M_2["m00"]))#центр окружности
radius_2 = int(np.sqrt((xs_2 - center_2[0])**2 + (ys_2 - center_2[1])**2).max())#радиус
cv2.circle(resize, (center_2[0], center_2[1]), radius_2, (0, 255, 0), 2)
cv2.circle(resize, (center_2[0], center_2[1]), 3, (0, 255, 0), -1)

cv2.imshow('Original_2', resize)
#cv2.imshow('thresh_2', thresh_2)

cv2.waitKey(0)
cv2.destroyAllWindows()