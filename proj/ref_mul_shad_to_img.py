import cv2
import matplotlib.pyplot as plt
import numpy as np 
from PIL import Image
import scipy.misc

def main():
    # ========================================================================
    imgpath = "./pic/"
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
    np_img_S=np.expand_dims(np_img_S,axis=2)
    
    # ========================================================================
    # Check shape of images
    
    print(np_img_R.shape)
    print(np_img_S.shape)
    
    # ========================================================================
    # Prepare 3-D tensor for orignal image

    ori_img=np.zeros((826, 600, 3))
    
    # ========================================================================
    # Perform dot product and insert result of dot product into 3rd dimension of ori_img
    # I'm not sure this logic works as I expected
    
    for i in range(0,826):
        for j in range(0,600):
            # print(np_img_R[i,j,:].shape)
            # (3,)
            # print(np.expand_dims(np_img_R[i,j,:],axis=1).shape)
            # (3,1)
            a=np.expand_dims(np_img_R[i,j,:],axis=1)
            # print(a.shape)
            b=np.expand_dims(np_img_S[i,j],axis=1)
            # print(b.shape)
            ori_img[i,j,:]=np.dot(a,b).squeeze()
            # print(ori_img[i,j,:].shape)
    
    # ========================================================================
    # This works?
    # ori_img = np_img_R * np_img_S[..., None]
    
    # ========================================================================
    # You try with log
    # ori_img[:]=np.log(np_img_R)+np.log(np_img_S)
    # ori_img[:]=np.log10(np_img_R)+np.log10(np_img_S)
    
    # ========================================================================
    # Check if value of "dot product" in inserted into ori_img

    print(np.dot(np_img_R[456,232,:],np_img_S[456,232]))
    # [130 250 255]
    print(ori_img.astype(int)[456,232,:])
    # [130 250 255]
    
    print(np.dot(np_img_R[825,599,:],np_img_S[825,599]))
    # [ 50  29 113]
    print(ori_img.astype(int)[825,599,:])
    # [ 50  29 113]
    
    # If I load images with PIL or scipy, result of dot product exceeds 255 like:
    # First case:
    # [47234 45562 43263]
    # [47234 45562 43263]
    # Secon case:
    # [4914 4893 4977]
    # [0 0 0]
    # unlike I load image with OpenCV3
    # But I don't figure out why this difference happens between OpenCV and PIL/scipy
    
    # ========================================================================
    # Check images
    np_img_S=np_img_S.squeeze()
    
    plt.imshow(np_img_R)
    plt.show()

    plt.imshow(np_img_S,cmap="gray")
    plt.show()

    plt.imshow(ori_img)
    plt.show()

if __name__ == "__main__":
    main()
