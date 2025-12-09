import cv2

'''img = cv2.imread('red.jpg')
#cv2.imshow('result', img)

new_img = cv2.resize(img, (img.shape[1] // 2, img.shape[0] // 2))
#print(img.shape)#возвращает высоту, ширину, и кол-во слоёв(т.е rgb)
#new_img[0:100, 0:150] срез
cv2.imshow('result', new_img[0:100, 0:150])

cv2.waitKey(0)'''

'''    Видео    '''

cap = cv2.VideoCapture("video/0_Christmas_Fireplace_1280x720.mp4")

while True:
    success, img = cap.read()#в success значение True/False, а в img само изображение
    cv2.imshow('results', img)

    if cv2.waitKey(10) & 0xFF == ord('q'):
        break

'''
cap = cv2.VideoCapture(0)# веб камера
cap.set(3, 500)
cap.set(4, 300)


while True:
    success, img = cap.read()#в success значение True/False, а в img само изображение
    cv2.imshow('results', img)

    if cv2.waitKey(10) & 0xFF == ord('q'):
        break'''

'''__ размытие__'''

'''img = cv2.imread('red.jpg')
img = cv2.GaussianBlur(img, (9,9), 0)
img = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
img = cv2.resize(img, (500,500))

cv2.imshow('result_4', img)
print(img.shape)

cv2.waitKey(0)'''

'''   углы изображения   '''

'''img = cv2.imread('red.jpg')
img = cv2.GaussianBlur(img, (9,9), 0)
img = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
img = cv2.resize(img, (500,500))

cv2.imshow('result_4', img)
print(img.shape)

cv2.waitKey(0)'''