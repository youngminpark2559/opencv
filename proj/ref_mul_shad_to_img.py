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
    np_img_S=np.expand_dims(np_img_S,axis=2)
    ori_img=np.zeros((256, 384, 3))
    
    # ========================================================================
    for i in range(0,256):
        for j in range(0,384):
            print("np_img_R[i,j,:].shape",np_img_R[i,j,:].shape)
            # (3,)
            a=np.expand_dims(np_img_R[i,j,:],axis=1)
            print("a.shape",a.shape)
            # (3,1)

            print("np_img_S[i,j]",np_img_S[i,j].shape)
            # (1,)
            b=np.expand_dims(np_img_S[i,j],axis=1)
            print("b.shape",b.shape)
            # (1, 1)
            
            # (3,1) of reflectance dot (1,1) of shading
            print("np.dot(a,b)",np.dot(a,b).shape)
            # (3, 1)
            print("np.dot(a,b).squeeze()",np.dot(a,b).squeeze().shape)
            # (3,)

            # ori_img[:]=[np.dot(a,b).squeeze()]
            ori_img[i,j,:]=np.dot(a,b).squeeze()
            # print("np.dot(a,b)",np.dot(a,b).shape)
            # print("np.dot(a,b).squeeze()",np.dot(a,b).squeeze().shape)
            # print(ori_img[i,j,:].shape)

    # ========================================================================
    # You try with log but it seems not working
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
    # https://github.com/youngmtool/opencv/blob/master/proj/pic/reflectance_01.png
    
    print("np_img_S",np_img_S.shape)
    plt.imshow(np_img_S,cmap="gray")
    plt.show()
    # https://github.com/youngmtool/opencv/blob/master/proj/pic/shading_01.png
    
    print("ori_img",ori_img.shape)
    plt.imshow(ori_img)
    plt.show()
    # https://github.com/youngmtool/opencv/blob/master/proj/pic/q_back.png

if __name__ == "__main__":
    main()
