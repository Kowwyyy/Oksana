import cv2
image = cv2.imread('images/balloon1.jpg')

x, y, w, h = 312, 165, 210, 240
cropped = image[y: y+h, x: x+w]
resized = cv2.resize(cropped, (600, 600))

cv2.imshow('Original', image)
cv2.imshow('Cropped', cropped)
cv2.imshow('Resize', resized)

cv2.waitKey(0)
cv2.destroyAllWindows()