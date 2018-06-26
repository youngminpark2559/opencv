import cv2
import matplotlib.pyplot as plt
import numpy as np 
from PIL import Image
import scipy.misc

def main():
    # ========================================================================
    imgpath = "./image_data/"
    reflectance=imgpath+"predicted_reflectance.png"
    shading=imgpath+"predicted_shading.png"

    # ========================================================================
    # Try to load image with PIL
    # img_RR = Image.open(reflectance)
    # img_RR=img_RR.convert('RGB')
    # np_img_R = np.array(img_RR)
    
    # img_SS = Image.open(shading)
    # img_SS.load()
    # np_img_S = np.asarray(img_SS, dtype="uint32")

    # ========================================================================
    # Try to load image with scipy
    
    # img_RR = scipy.misc.imread(reflectance, flatten=False, mode='RGB')
    # np_img_R=np.array(img_RR)
    
    # ========================================================================
    # Try to load image with OpenCV3
    
    img_R = cv2.imread(reflectance, 1)
    img_S = cv2.imread(shading, 0)

    img_R=cv2.cvtColor(img_R,cv2.COLOR_BGR2RGB)

    np_img_R=np.array(img_R)
    np_img_S=np.array(img_S)
    
    # ========================================================================
    # Check shape of images
    
    print(np_img_R.shape)
    print(np_img_S.shape)
    
    # ========================================================================
    # Prepare 3-D tensor for orignal image

    ori_img=np.zeros((826, 600, 3))
    
    # ========================================================================
    # Perform dot product and insert it into 3rd dimension of c
    # I'm nor sure this logic works as I expected
    # When I display ori_img with ori_img[:,:,:], many elements of 3-D tensor was stuffed with 0
    
    for i in range(0,825):
        for j in range(0,599):
            ori_img[i,j,:]=np.dot(np_img_R[i,j,:],np_img_S[i,j])

    # ========================================================================
    # Check if value of "dot product" in inserted into ori_img
    
    print(np.dot(np_img_R[456,232,:],np_img_S[456,232]))
    # [130 250 255]
    print(ori_img.astype(int)[456,232,:])
    # [130 250 255]
    
    print(np.dot(np_img_R[825,599,:],np_img_S[825,599]))
    # [ 50  29 113]
    print(ori_img.astype(int)[825,599,:])
    # [0 0 0]
    # Above both should be same but they're different
    
    # First case with [456,232,:] indices has same value
    # But second case with [825,599,:] indices has different value
    
    # And if I load images with PIL or scipy, result of dot product exceeds 255 like:
    # First case:
    # [47234 45562 43263]
    # [47234 45562 43263]
    # Secon case:
    # [4914 4893 4977]
    # [0 0 0]
    # But I don't figure out why this difference happens between OpenCV and PIL/scipy
    
    # ========================================================================
    # Check images
    
    plt.imshow(np_img_R)
    plt.show()

    plt.imshow(np_img_S,cmap="gray")
    plt.show()

    plt.imshow(ori_img)
    plt.show()

if __name__ == "__main__":
    main()
