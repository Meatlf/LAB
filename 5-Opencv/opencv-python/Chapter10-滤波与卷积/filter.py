import cv2
pic = cv2.imread('./5.jpg')
pic = cv2.resize(pic, (720, 720), interpolation=cv2.INTER_CUBIC)
cv2.imshow('', pic)
cv2.imwrite('6.jpg',pic)
print(pic.shape)
cv2.waitKey(0)
cv2.destroyAllWindows()
