# 参考资料： OpenCV-Python Tutorials Documentation 1.2 Gui Features in OpenCV
import numpy as np
import cv2

# Create a black image
img = np.zeros((512, 512, 3), np.uint8)

# Draw a diagonal blue line with thickness of 5 px
img = cv2.line(img, (0, 0), (511, 511), (255, 0, 0), 5)

# Draw a rectangle
img = cv2.rectangle(img,(384,0),(510,128),(0,255,0),3)

# Draw a circle
img = cv2.circle(img,(447,63),63,(0,0,255),-1)

cv2.imshow("Image", img)
cv2.waitKey(0)
cv2.destroyAllWindows()