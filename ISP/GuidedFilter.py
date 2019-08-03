# 导入库
import argparse
import cv2
import matplotlib.pyplot as plt
import skimage
import numpy as np

# 构造参数解析器
ap = argparse.ArgumentParser()
ap.add_argument("-i", "--image", required=True, help = "Path to the image")
args = vars(ap.parse_args())

# 加载图像并显示
img = cv2.imread(args["image"],1)
img = img[:,:,::-1]
guide = cv2.cvtColor(img, cv2.COLOR_RGB2GRAY)

# 进行导向滤波
dst1 = cv2.ximgproc.guidedFilter(
            guide=guide, src=img, radius=16, eps=50, dDepth=-1)
dst2 = cv2.ximgproc.guidedFilter(
            guide=guide, src=img, radius=16, eps=200, dDepth=-1)
dst3 = cv2.ximgproc.guidedFilter(
            guide=guide, src=img, radius=16, eps=1000, dDepth=-1)

# 绘制图片
images = [img,[dst1,dst2,dst3]]
titles =    [
                'Original',
                ['Guided Filter eps=50','Guided Filter eps=200','Guided Filter eps=1000']
            ]

# 绘制原图
plt.figure(figsize=(20,20))     # 图片对话框的大小

plt.subplot(2, 3, 2),plt.imshow(images[0])
plt.title(titles[0], fontsize=10),plt.xticks([]), plt.yticks([])

plt.subplot(2, 3, 4),plt.imshow(images[1][0])
plt.title(titles[1][0], fontsize=10),plt.xticks([]), plt.yticks([])

plt.subplot(2, 3, 5),plt.imshow(images[1][1])
plt.title(titles[1][1], fontsize=10),plt.xticks([]), plt.yticks([])

plt.subplot(2, 3, 6),plt.imshow(images[1][2])
plt.title(titles[1][2], fontsize=10),plt.xticks([]), plt.yticks([])

plt.savefig('1_out.png', transparent=True, dpi=300, pad_inches = 0)
plt.show()