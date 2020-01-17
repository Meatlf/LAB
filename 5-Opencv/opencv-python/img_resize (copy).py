import cv2
pic = cv2.imread('./3.jpg')
cv2.imshow('', pic)
cv2.imwrite('2.jpg',pic)
print(pic.shape)
cv2.waitKey(0)
cv2.destroyAllWindows()
