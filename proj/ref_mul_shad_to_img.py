import cv2
import matplotlib.pyplot as plt
import numpy as np 
from PIL import Image
import scipy.misc

# ========================================================================

def load_image( infilename ) :
    img = Image.open( infilename )
    img.load()
    data = np.asarray( img, dtype="int32" )
    return data

def save_image( npdata, outfilename ) :
    img = Image.fromarray( np.asarray( np.clip(npdata,0,255), dtype="uint8"), "L" )
    img.save( outfilename )

def main():
    imgpath = "./pic/"
    reflectance=imgpath+"reflectance_01.png"
    shading=imgpath+"shading_01.png"
    
    # ========================================================================
    img_R = cv2.imread(reflectance, 1)
    img_S = cv2.imread(shading, 0)

    # You convert BGR reflectance image to RGB reflectance image
    img_R=cv2.cvtColor(img_R,cv2.COLOR_BGR2RGB)

    # ========================================================================
    np_img_R=np.array(img_R)
    np_img_S=np.array(img_S)
    # You convert shape of shading image (256, 384) into (256, 384, 1) 
    # to perform np.dot() with reflectance image
    np_img_S=np.expand_dims(np_img_S,axis=2)
    # This is placeholder for recovered original image from dot product of img_R and img_S
    ori_img=np.zeros((256, 384, 3))
    
    # ========================================================================
    for i in range(0,256):
        for j in range(0,384):
            # print(np_img_R[i,j,:].shape)
            # (3,)
            # print(np.expand_dims(np_img_R[i,j,:],axis=1).shape)
            # (3,1)
            a=np.expand_dims(np_img_R[i,j,:],axis=1)
            # print(a.shape)
            
            b=np.expand_dims(np_img_S[i,j],axis=1)
            # print(b.shape)
            
            # ori_img[:]=[np.dot(a,b).squeeze()]
            ori_img[i,j,:]=np.dot(a,b).squeeze()
            # print("np.dot(a,b)",np.dot(a,b).shape)
            # print("np.dot(a,b).squeeze()",np.dot(a,b).squeeze().shape)
            # print(ori_img[i,j,:].shape)

    # a=np.expand_dims(np_img_R[i,j,:],axis=1)
    # b=np.expand_dims(np_img_S[i,j],axis=1)
    # ori_img[:]=a+b

    # ========================================================================
    # ori_img[:]=np.log10(np_img_R)+np.log10(np_img_S)

    # ========================================================================
    # You recover shading to 2D array (256, 384) to make it grayscale image
    np_img_S=np_img_S.squeeze()

    # ========================================================================
    print(np_img_R.shape)
    print(ori_img.shape)

    # ========================================================================
    print("np_img_R",np_img_R.shape)
    plt.imshow(np_img_R)
    plt.show()

    print("np_img_S",np_img_S.shape)
    plt.imshow(np_img_S,cmap="gray")
    plt.show()

    print("ori_img",ori_img.shape)
    plt.imshow(ori_img)
    plt.show()

if __name__ == "__main__":
    main()
