#include<stdio.h>
#include<stdlib.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image/stb_image_write.h"

int main(void)
{
    int conversion;
    printf("Welcome to our Project...\n");
    printf("This program is a basic photo editor inside the Visual Studio Code Platform.\n");
    printf("\nThis program has the following features :");

    printf("\n 1) Crop an image.");
    printf("\n 2) Extract the RGB Components of the image.");
    printf("\n 3) Convert the image to a greyscale image.");
    printf("\n 4) Convert the image to a Black and White image.");
    printf("\n 5) Convert the image to sepia colour format.");
    printf("\n 6) Interchange the components of the image.");

    printf("\nTo use those conversions, write the number of the conversion you need : ");
    scanf("%d",&conversion);

    switch(conversion){
        case 1 :     {int width,height,channels,a,b,i,j,c=-1,d=-1,m,n;
        
    unsigned char *img = stbi_load("project.png",&width,&height,&channels,0);
    if(img == NULL){
        printf("Error in loading image.\n");
    }
    printf("Its width is %d and height is %d\n",width,height);
    printf("Enter the starting coordinates : ");
    scanf("%d %d",&a,&b);
    printf("Enter the ending coordinates : ");
    scanf("%d %d",&m,&n);

    size_t im_si = (m-a+1)*(n-b+1)*channels;
    size_t img_siz = (width)*(n+1)*channels;

    unsigned char *ima_si = malloc(im_si);
    if(ima_si == NULL){
        printf("Error in allocation.");
    }

    for(unsigned char *p = img,*pg=ima_si;p!=img_siz+img;p+=channels) { 
        c+=1;
        c=c%(width);
        if(c==0){
            d+=1;
        }

        if(c>=a && c<=m && d>=b && d<=n){
        *pg = *p;
        *(pg+1) = *(p+1);
        *(pg+2) = *(p+2);

        if(channels==4){
            *(pg+3) = *(p+3);
        }

        pg+=channels;

        }
        
    }    

    //stbi_write_jpg("Crop.jpg", a, b, channels, ima_si, 100);
    stbi_write_png("Crop.png", (m-a+1), (n-b+1), channels, ima_si, (m-a+1) * channels);

    stbi_image_free(img);
    free(ima_si);}

    break;

    case 2 : 
    
    {
    int number;
    printf("What component you need?\n");
    printf("Red - 1, Green - 2, Blue - 3 : ");
    scanf("%d",&number);

    switch(number){
        case 1 :
        {
            int width, height, channels;
    unsigned char *img = stbi_load("project.png", &width, &height, &channels, 0);
    if(img == NULL) {
        printf("Error in loading the image\n");
        exit(1);
    }

    size_t img_size = width * height * channels;

    unsigned char *gray_img = malloc(img_size);
    if(gray_img == NULL) {
        printf("Unable to allocate memory for the gray image.\n");
        exit(1);
    }

    for(unsigned char *p = img, *pg = gray_img; p != img + img_size; p += channels, pg += channels) {
        *pg = *(p);
        *(pg+1) = (0);
        *(pg+2) = (0);

        if(channels == 4){
            *(pg+3) = *(p+3);
        }

    }
    //stbi_write_jpg("Red.jpg", width, height, channels, gray_img, 100);
    stbi_write_png("Red.png", width, height, channels, gray_img, width * channels);
    }
    break;

    case 2 :
    {
        int width, height, channels;
    unsigned char *img = stbi_load("project.png", &width, &height, &channels, 0);
    if(img == NULL) {
        printf("Error in loading the image\n");
        exit(1);
    }

    size_t img_size = width * height * channels;

    unsigned char *gray_img = malloc(img_size);
    if(gray_img == NULL) {
        printf("Unable to allocate memory for the gray image.\n");
        exit(1);
    }

    for(unsigned char *p = img, *pg = gray_img; p != img + img_size; p += channels, pg += channels) {
        *pg = (0);
        *(pg+1) = *(p+1);
        *(pg+2) = (0);

        if(channels == 4){
            *(pg+3) = *(p+3);
        }

    }
    //stbi_write_jpg("Green.jpg", width, height, channels, gray_img, 100);
    stbi_write_png("Green.png", width, height, channels, gray_img, width * channels);
    }
    break;

    case 3: 
    {
        int width, height, channels;
    unsigned char *img = stbi_load("project.png", &width, &height, &channels, 0);
    if(img == NULL) {
        printf("Error in loading the image\n");
        exit(1);
    }

    size_t img_size = width * height * channels;

    unsigned char *gray_img = malloc(img_size);
    if(gray_img == NULL) {
        printf("Unable to allocate memory for the gray image.\n");
        exit(1);
    }

    for(unsigned char *p = img, *pg = gray_img; p != img + img_size; p += channels, pg += channels) {
        *pg = (0);
        *(pg+1) = (0);
        *(pg+2) = *(p+2);

        if(channels == 4){
            *(pg+3) = *(p+3);
        }

    }
    //stbi_write_jpg("Blue.jpg", width, height, channels, gray_img, 100);
    stbi_write_png("Blue.png", width, height, channels, gray_img, width * channels);
    }
    break;

    default : printf("Enter the correct case number for Red,Green or Blue...");
    }
    }

    break;


    case 3: 
    {
        int width, height, channels;
    unsigned char *img = stbi_load("project.png", &width, &height, &channels, 0);
    if(img == NULL) {
        printf("Error in loading the image\n");
        exit(1);
    }

    size_t img_size = width * height * channels;
    int gray_channels = channels == 4 ? 2 : 1;
    size_t gray_img_size = width * height * gray_channels;

    unsigned char *gray_img = malloc(gray_img_size);
    if(gray_img == NULL) {
        printf("Unable to allocate memory for the gray image.\n");
        exit(1);
    }

    for(unsigned char *p = img, *pg = gray_img; p != img + img_size; p += channels, pg += gray_channels) {
        *pg = (uint8_t)((*p)*0.299 + *(p + 1)*0.587 + *(p + 2)*0.114);
        if(channels == 4) {
            *(pg + 1) = *(p + 3);
        }
    }

    //stbi_write_jpg("Grayscale.jpg", width, height, gray_channels, gray_img, 100);
    stbi_write_png("Grayscale.png", width, height, gray_channels, gray_img, width * gray_channels);

    stbi_image_free(img);
    free(gray_img);
    }
    break;
    
    case 5 :
    {
        int width, height, channels;
    unsigned char *img = stbi_load("project.png", &width, &height, &channels, 0);
    if(img == NULL) {
        printf("Error in loading the image\n");
        exit(1);
    }

    size_t img_size = width * height * channels;

    unsigned char *sepia_img = malloc(img_size);
    if(sepia_img == NULL) {
        printf("Unable to allocate memory for the sepia image.\n");
        exit(1);
    }

    for(unsigned char *p = img, *pg = sepia_img; p != img + img_size; p += channels, pg += channels) {
        *pg       = (uint8_t)fmin(0.393 * *p + 0.769 * *(p + 1) + 0.189 * *(p + 2), 255.0);         
        *(pg + 1) = (uint8_t)fmin(0.349 * *p + 0.686 * *(p + 1) + 0.168 * *(p + 2), 255.0);         
        *(pg + 2) = (uint8_t)fmin(0.272 * *p + 0.534 * *(p + 1) + 0.131 * *(p + 2), 255.0);                
        if(channels == 4) {
            *(pg + 3) = *(p + 3);
        }
    }

    //stbi_write_jpg("Sepia.jpg", width, height, channels, sepia_img, 100);
    stbi_write_png("Sepia.png", width, height, channels, sepia_img, width * channels);

    stbi_image_free(img);
    free(sepia_img);
    }
    break;

    case 4 :
    {
    int width, height, channels;
    unsigned char *img = stbi_load("project.png", &width, &height, &channels, 0);
    if(img == NULL) {
        printf("Error in loading the image\n");
        exit(1);
    }

    size_t img_size = width * height * channels;
    int bchannels= channels == 4 ? 2 : 1;
    size_t newimg_siz = width*height*bchannels;

    unsigned char *grey_img = malloc(newimg_siz);
    if(grey_img == NULL){
        printf("Error in allocation.");
    }

    int n;
    for(unsigned char *a = img,*b = grey_img;a!= img+img_size;a+=channels,b+=bchannels){
            n = (*a + *(a+1) + *(a+2))/3;

            if(n>=128){
                *b = 255;
            }
            else{
                *b = 0;
            }

            if(channels == 4){
                *(b+1) = *(a+3);
            }
    }


    stbi_write_jpg("Black_and_White.jpg",width,height,bchannels,grey_img,100);
    //stbi_write_png("Black_and_White.png", width, height, bchannels, grey_img, width * bchannels);


    stbi_image_free(img);
    free(grey_img);
    }
    break;

    case 6 :
    {
        int casenum;
        printf("1)Red <-> Green");
        printf("\n2)Red <-> Blue");
        printf("\n3)Blues <-> Green");

        printf("\n4)Red -> Blue,Blue -> Green, Green -> Red");
        printf("\n5)Red -> Green,Green -> Blue, Blue -> Red");

        printf("\nEnter the case number : ");
        scanf("%d",&casenum);

        switch(casenum){
            case 1 :
                {
        int width, height, channels;
    unsigned char *img = stbi_load("project.png", &width, &height, &channels, 0);
    if(img == NULL) {
        printf("Error in loading the image\n");
        exit(1);
    }

    size_t img_size = width * height * channels;

    unsigned char *gray_img = malloc(img_size);
    if(gray_img == NULL) {
        printf("Unable to allocate memory for the gray image.\n");
        exit(1);
    }

    for(unsigned char *p = img, *pg = gray_img; p != img + img_size; p += channels, pg += channels) {
        *pg = *(p+1);
        *(pg+1) = *(p);
        *(pg+2) = *(p+2);

        if(channels == 4){
            *(pg+3) = *(p+3);
        }

    }
    //stbi_write_jpg("RG.jpg", width, height, channels, gray_img, 100);
    stbi_write_png("RG.png", width, height, channels, gray_img, width * channels);
    }
    break;

    case 2 :
                {
        int width, height, channels;
    unsigned char *img = stbi_load("project.png", &width, &height, &channels, 0);
    if(img == NULL) {
        printf("Error in loading the image\n");
        exit(1);
    }

    size_t img_size = width * height * channels;

    unsigned char *gray_img = malloc(img_size);
    if(gray_img == NULL) {
        printf("Unable to allocate memory for the gray image.\n");
        exit(1);
    }

    for(unsigned char *p = img, *pg = gray_img; p != img + img_size; p += channels, pg += channels) {
        *pg = *(p+2);
        *(pg+1) = *(p+1);
        *(pg+2) = *(p);

        if(channels == 4){
            *(pg+3) = *(p+3);
        }

    }
    //stbi_write_jpg("RB.jpg", width, height, channels, gray_img, 100);
    stbi_write_png("RB.png", width, height, channels, gray_img, width * channels);
    }
    break;


    case 3 :
                {
        int width, height, channels;
    unsigned char *img = stbi_load("project.png", &width, &height, &channels, 0);
    if(img == NULL) {
        printf("Error in loading the image\n");
        exit(1);
    }

    size_t img_size = width * height * channels;

    unsigned char *gray_img = malloc(img_size);
    if(gray_img == NULL) {
        printf("Unable to allocate memory for the gray image.\n");
        exit(1);
    }

    for(unsigned char *p = img, *pg = gray_img; p != img + img_size; p += channels, pg += channels) {
        *pg = *(p);
        *(pg+1) = *(p+2);
        *(pg+2) = *(p+1);

        if(channels == 4){
            *(pg+3) = *(p+3);
        }

    }
    //stbi_write_jpg("BG.jpg", width, height, channels, gray_img, 100);
    stbi_write_png("BG.png", width, height, channels, gray_img, width * channels);
    }
    break;

    case 4 :

                {
        int width, height, channels;
    unsigned char *img = stbi_load("project.png", &width, &height, &channels, 0);
    if(img == NULL) {
        printf("Error in loading the image\n");
        exit(1);
    }

    size_t img_size = width * height * channels;

    unsigned char *gray_img = malloc(img_size);
    if(gray_img == NULL) {
        printf("Unable to allocate memory for the gray image.\n");
        exit(1);
    }

    for(unsigned char *p = img, *pg = gray_img; p != img + img_size; p += channels, pg += channels) {
        *pg = *(p+1);
        *(pg+1) = *(p+2);
        *(pg+2) = *(p);

        if(channels == 4){
            *(pg+3) = *(p+3);
        }

    }
    //stbi_write_jpg("RGB1.jpg", width, height, channels, gray_img, 100);
    stbi_write_png("RGB1.png", width, height, channels, gray_img, width * channels);
    }
    break;


    case 5 :

                {
        int width, height, channels;
    unsigned char *img = stbi_load("project.png", &width, &height, &channels, 0);
    if(img == NULL) {
        printf("Error in loading the image\n");
        exit(1);
    }

    size_t img_size = width * height * channels;

    unsigned char *gray_img = malloc(img_size);
    if(gray_img == NULL) {
        printf("Unable to allocate memory for the gray image.\n");
        exit(1);
    }

    for(unsigned char *p = img, *pg = gray_img; p != img + img_size; p += channels, pg += channels) {
        *pg = *(p+2);
        *(pg+1) = *(p);
        *(pg+2) = *(p+1);

        if(channels == 4){
            *(pg+3) = *(p+3);
        }

    }
    //stbi_write_jpg("RGB2.jpg", width, height, channels, gray_img, 100);
    stbi_write_png("RGB2.png", width, height, channels, gray_img, width * channels);
    }
    break;


    default : printf("Enter the correct case number for conversion..");

        }

    }
    default : printf("Enter the correct case number for image conversion...");


    }
}   