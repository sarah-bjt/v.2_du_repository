#include <sil/sil.hpp>
#include "random.hpp"
#include <cmath>
#include <iomanip>
#include <numbers>
#include <math.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
//

// Exercice 1 : Ne garder que le vert

void onlyGreen (sil::Image image)
{
    for (glm::vec3& color : image.pixels())
    {
    color.r = 0.f;
    color.b = 0.f;
    }
    image.save("output/ex01onlyGreen.png");
}

// Exercice 2 : Echanger les canaux

void blueAndRedReverse (sil::Image image)
{
    for (glm::vec3& color : image.pixels())
    {
        float a {color.r};
        color.r = color.b;
        color.b = a;
    }
    image.save("output/ex02blueAndRedReverse.png");    
}

void canaux(sil::Image logo)
{
    for(glm::vec3& color : logo.pixels())
    {
        std::swap(color.r, color.b);
    }
        logo.save("output/canaux.png");
};

// Exercice 3 : Noir & Blanc

void blackAndWhite (sil::Image image)
{
    for (glm::vec3& color : image.pixels())
    {
        float moy {(color.r+color.b+color.g)/3};
        color.g = moy;
        color.r = moy;
        color.b = moy;
    }
    image.save("output/ex03blackAndWhite.png");
}

// Exercice 4 : Négatif

void inverteColor (sil::Image image)
{
    for (glm::vec3& color : image.pixels())
    {
        color.g = 1 - color.g;
        color.b = 1 - color.b;
        color.r = 1 - color.r;
    }
    image.save("output/ex04inverteColor.png");    
}

// Exercice 5 : Dégradé

void degrader ()
{
    sil::Image image{300/*width*/, 200/*height*/};
    for (float x{0}; x < image.width(); x++)
    {
        for (float y{0}; y < image.height(); y++)
        {
            float couleur  = x/300;
            image.pixel(x,y).r = couleur;
            image.pixel(x,y).b = couleur;
            image.pixel(x,y).g = couleur;   
        }
    }
    image.save("output/ex05degrader.png");    
}

// Exercice 6 : Miroir

void miroir (sil::Image image)
{
    sil::Image copyImage {image.width(), image.height()};
    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            copyImage.pixel(x, y).r = image.pixel(image.width()-1-x, y).r;
            copyImage.pixel(x, y).b = image.pixel(image.width()-1-x, y).b;
            copyImage.pixel(x, y).g = image.pixel(image.width()-1-x, y).g;
        }
    }
    copyImage.save("output/ex06miroir.png");   
}

void miroir2(sil::Image logo)
{
    sil::Image logo2 {logo};
    for (int x{0}; x < logo2.width(); ++x)
    {
        for (int y {0}; y < logo2.height(); ++y)
        {
            float variable2 {logo2.width() - 1.f - x};
            logo.pixel(x, y).r = logo2.pixel(variable2, y).r;
            logo.pixel(x, y).b = logo2.pixel(variable2, y).b;
            logo.pixel(x, y).g = logo2.pixel(variable2, y).g;
        }
    }
        logo.save("output/ex06miroir02.png");
};

// Exercice 7 : Image bruité

void imageBruit (sil::Image image)
{
    for (glm::vec3& color : image.pixels())
    {
        int isPixelBruit {random_int(0, 4)};
        if (isPixelBruit == 1)
        {
            color.r =  random_float(0, 1);
            color.b =  random_float(0, 1);
            color.g =  random_float(0, 1);
        }
    }
    image.save("output/ex07imageBruit.png");    
}

void bruite(sil::Image logo)
{
    int i {0};
    while(i < 200)
    {
        int x {random_int(0, logo.width()+1)};
        int y {random_int(0, logo.height()+1)};
        logo.pixel(x, y).r = random_float(0,1);
        logo.pixel(x, y).b = random_float(0,1);
        logo.pixel(x, y).g = random_float(0,1);
        i ++;
    }
        logo.save("output/bruite.png");
};

// Exercice 8 : Rotation de 90° ATTENTION NE FONCTIONNE PAS

// void rotation90 (sil::Image image, sil::Image result) // attention ne fonctionne pas 
// {
//     for (int x{0}; x < result.width(); x++)
//     {
//         for (int y{0}; y < result.height(); y++)
//         {
//             result.pixel(x, y) = image.pixel(image.height()-x, image.width()-y);
//         }
//     }
//     result.save("output/ex08rotation90.png");
// }

// Exercice 9 : RGB split


// void RGBsplit (sil::Image image) // effet arlequin
// {
//     sil::Image copy {image};
//     for (int x{0}; x < image.width()-(image.width()/5); x++) // pour le rouge vers la drt
//     {
//         for (int y{0}; y < image.height(); y++)
//         {
//             copy.pixel(x+(image.width()/5), y).r = image.pixel(x,y).r;
//         }
//     }
//     for (int x{(image.width()/5)}; x< image.width(); x++) // pour le bleu vers la gch
//     {
//         for (int y{0}; y < image.height(); y++)
//         {
//             copy.pixel(x - (image.width()/5), y).b = image.pixel(x,y).b;
//         }
//     }
//     copy.save("output/ex09RGBsplit.png");
// }

void RGBsplit (sil::Image image)
{
    sil::Image copy {image.width(),image.height()};
    for (int x{0}; x < image.width()-(image.width()/9); x++) // pour le rouge vers la drt
    {
        for (int y{0}; y < image.height(); y++)
        {
            copy.pixel(x+(image.width()/9), y).r = image.pixel(x,y).r;
        }
    }
    for (int x{(image.width()/9)}; x< image.width(); x++) // pour le bleu vers la gch
    {
        for (int y{0}; y < image.height(); y++)
        {
            copy.pixel(x - (image.width()/9), y).b = image.pixel(x,y).b;
        }
    }
    for (int x{}; x< image.width(); x++) // pour le vert
    {
        for (int y{0}; y < image.height(); y++)
        {
            copy.pixel(x , y).g = image.pixel(x,y).g;
        }
    }
    copy.save("output/ex09RGBsplit.png");
}

// Exercice 10 : Luminosité

void luminosite (sil::Image image)
{

    for (glm::vec3& color : image.pixels())
    {
        {
            color.g = pow(color.g, 0.6);
            color.r = pow(color.r, 0.6);
            color.b = pow(color.b, 0.6);
        }
    }
    image.save("output/ex10luminosite.png");
}

// Exercice 11 : Disque

void disque ()
{
    sil::Image image{500/*width*/, 500/*height*/};
    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            if( pow((x-250),2)+pow((y-250),2)< pow(200,2) )
            {
                image.pixel(x,y).g = 1;
                image.pixel(x,y).r = 1;
                image.pixel(x,y).b = 1;
            }
        }
    }
    image.save("output/ex11disque.png");
}

// Exercice 12 : Cercle
void cercle (int thickness)
{
    sil::Image image{500/*width*/, 500/*height*/};
    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            if (pow((x-250),2)+pow((y-250),2)< pow(200,2) && pow((x-250),2)+pow((y-250),2)> pow(200-thickness,2) )
            {
                image.pixel(x,y).g = 1;
                image.pixel(x,y).r = 1;
                image.pixel(x,y).b = 1;
            }
        }
    }
    image.save("output/ex12cercle.png");
}
// Exercice 13 : Rosace

void dessineCercle( sil::Image& image, float x0 , float y0 , float rayon, float thickness)
{
    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height() ; y++)
        {
        if (pow((x-x0),2)+pow((y-y0),2)< pow(rayon,2) && pow((x-x0),2)+pow((y-y0),2)> pow(rayon-thickness,2) )
                { 
                    image.pixel(x,y).g = 1;
                    image.pixel(x,y).r = 1;
                    image.pixel(x,y).b = 1;
                }
        }        
    }
}

void rosace(sil::Image image)
{
    dessineCercle (image, 250,250,100,10); //centre
    dessineCercle (image,250-95,250,100,10); //gch
    dessineCercle (image,250+95,250,100,10); //dte
    dessineCercle (image,250 +95*std::cos((2*M_PI)/3.0),250 +95*std::sin((2*M_PI)/3),100,10); 
    dessineCercle (image,250 +95*std::cos((M_PI)/3.0),250 +95*std::sin((M_PI)/3),100,10); 
    dessineCercle (image,250 +95*std::cos((4*M_PI)/3.0),250 +95*std::sin((4*M_PI)/3),100,10); 
    dessineCercle (image,250 +95*std::cos((5*M_PI)/3.0),250 +95*std::sin((5*M_PI)/3),100,10); 
    image.save("output/ex13rosace.png");
}

// Exercice 14 : Mosaïque (mosaique1 stylé mais pas voulu)

// void mosaique1(sil::Image logo)
// {
//     sil::Image logo2 {logo.width()*5, logo.height()*5};
//     for (int x{0}; x < logo.width(); ++x)
//     {
//         for (int y{0}; y < logo.height(); ++y)
//         {
//             for (int i{0}; i < 5; ++i)
//             {
//                 for(int j{0}; j < 5; ++j)
//                 {
//                     logo2.pixel(x*i, y*j).r = logo.pixel(x, y).r;
//                     logo2.pixel(x*i, y*j).b = logo.pixel(x, y).b;
//                     logo2.pixel(x*i, y*j).g = logo.pixel(x, y).g;
//                 }
//             }
//         }
//     }
//     logo2.save("output/ex14mosaique.png");
// }


void mosaique2(sil::Image logo)
{
    sil::Image logo2 {logo.width()*5, logo.height()*5};
    for (int x{0}; x < logo.width(); ++x)
    {
        for (int y{0}; y < logo.height(); ++y)
        {
            for (int i{0}; i < 5; ++i)
            {
            for (int j{0}; j < 5; ++j)
                {
                    logo2.pixel(x+i*logo.width(), y+j*logo.height()).r = logo.pixel(x, y).r;
                    logo2.pixel(x+i*logo.width(), y+j*logo.height()).b = logo.pixel(x, y).b;
                    logo2.pixel(x+i*logo.width(), y+j*logo.height()).g = logo.pixel(x, y).g;
                }
            }
        }
    }
    
    // for (int x{0}; x < logo2.width(); ++x)
    // {
    //     for (int y{0}; y < logo.height(); ++y)
    //     {
    //         for (int i{0}; i < 5; ++i)
    //         {
    //             logo2.pixel(x, y+i*logo.height()).r = logo2.pixel(x, y).r;
    //             logo2.pixel(x, y+i*logo.height()).b = logo2.pixel(x, y).b;
    //             logo2.pixel(x, y+i*logo.height()).g = logo2.pixel(x, y).g;
    //         }
    //     }
    // }
    logo2.save("output/ex14mosaique2.png");
}

// Exercice 15 : Mosaïque miroir

void mosaique_miroir(sil::Image logo)
{
    sil::Image logo2 {logo.width()*5, logo.height()*5};

    for (int x{0}; x < logo2.width(); x += 1)
    {
        for (int y{0}; y < logo2.height(); y += 1)
        {
            int NewX {x%logo.width()};
            int NewY {y%logo.height()};
            if ((x/logo.width()) % 2 == 1)
            {
                NewX = {logo.width() - 1 - NewX} ;
            }
            if ((y/logo.height()) % 2 == 1)
            {
               NewY = {logo.height() - 1 - NewY};
            }
            logo2.pixel(x, y) = logo.pixel(NewX, NewY);
        }
    }
    logo2.save("output/ex15MosaiqueMiroir.png");
}

// Exercice 16 : Glitch


//                                              glitch avec while
// void glitch(sil::Image image)  
// {
//     sil::Image imageGlitch{image};
//     int width {image.width()};
//     for (int y{0}; y < image.height()-1 ; y++)
//     {
//         for (int x{0}; x < image.width()-4; x++)
//         {
//             int isPixelGlitch {random_int(0,5)};
//             if (isPixelGlitch == 1 && imageGlitch.pixel(x,y) != image.pixel(x,y))
//             {
//                 int longuereGlitch {random_int(5,20)};
//                 int indiceGlitch {random_int(0,width)};
//                 int count {0};
//                 while (count<indiceGlitch)
//                 {
//                     imageGlitch.pixel(x,y) = image.pixel(x+5,y+2);
//                     count += 1;
//                 }
//             }
            
//         }
//     }
//     imageGlitch.save("output/ex16glitch.png");
// }

//                                         Glitch avec for
// void glitch(sil::Image image)
// {
//     sil::Image imageGlitch{image};
//     int width {image.width()};

//     for (int y{0}; y < image.height()-10; ++y) 
//     {
//         for (int x{0}; x < image.width()-10; ++x) 
//         {
//             int isPixelGlitch {random_int(0,10)};
//             if (isPixelGlitch == 1 && imageGlitch.pixel(x, y).r == image.pixel(x, y).r && imageGlitch.pixel(x, y).b == image.pixel(x, y).b && imageGlitch.pixel(x, y).g == image.pixel(x, y).g) 
//             {
//                 int longueurGlitch {30};
//                 //int longueurGlitch {random_int(10,30)};
//                 //int indiceGlitch {random_int(0,width)};
//                 for (int i{0}; i < longueurGlitch ; ++i) 
//                 {
//                     imageGlitch.pixel(x, y).r = image.pixel(x+5, y+2).r;
//                     imageGlitch.pixel(x, y).b = image.pixel(x+5, y+2).b;
//                     imageGlitch.pixel(x, y).g = image.pixel(x+5, y+2).g;
//                 }
//             }
//         }
//     }

//     imageGlitch.save("output/ex16glitch.png");
// }
//                                                               Glitch pas ouf qui fonctionne pas
// void glitch (sil::Image image)
// {
//     sil::Image imageGlitch {image};
//     int width {image.width()};
//     int height {image.height()};
//     int nbr_de_glitch {random_int(10,60)};
//     int count{0};
//     while(count<nbr_de_glitch)
//     {
//         int x0_glitch {random_int(0,width-20)};
//         int y0_glitch {random_int(0,height-20)};
//         int lenght_glitch {random_int(6,10)};
//         int thinckness_glitch {random_int(1,6)};
//         for (int x{x0_glitch}; x < x0_glitch + lenght_glitch; ++x)
//         {
//             for (int y{y0_glitch}; y < y0_glitch + thinckness_glitch; ++y)
//             {
//                 if(x0_glitch < width/2 && y0_glitch < height/2) //bas-gch
//                 {
//                     imageGlitch.pixel(x, y).r = image.pixel(x+width/2, y+height/2).r;
//                     imageGlitch.pixel(x, y).b = image.pixel(x+width/2, y+height/2).b;
//                     imageGlitch.pixel(x, y).g = image.pixel(x+width/2, y+height/2).g;
//                 }
//                 else if(x0_glitch < width/2 && y0_glitch > height/2) //haut-gch
//                 {
//                     imageGlitch.pixel(x, y).r = image.pixel(x+width/2, y-height/2).r;
//                     imageGlitch.pixel(x, y).b = image.pixel(x+width/2, y-height/2).b;
//                     imageGlitch.pixel(x, y).g = image.pixel(x+width/2, y-height/2).g;
//                 }
//                 else if(x0_glitch > width/2 && y0_glitch < height/2) //bas-drt
//                 {
//                     imageGlitch.pixel(x, y).r = image.pixel(x-width/2, y+height/2).r;
//                     imageGlitch.pixel(x, y).b = image.pixel(x-width/2, y+height/2).b;
//                     imageGlitch.pixel(x, y).g = image.pixel(x-width/2, y+height/2).g;
//                 }
//                 else if(x0_glitch > width/2 && y0_glitch > height/2) //haut-drt
//                 {
//                     imageGlitch.pixel(x, y).r = image.pixel(x-width/2, y-height/2).r;
//                     imageGlitch.pixel(x, y).b = image.pixel(x-width/2, y-height/2).b;
//                     imageGlitch.pixel(x, y).g = image.pixel(x-width/2, y-height/2).g;
//                 }
//             }
//         }

//     }
//     imageGlitch.save("output/ex16glitch.png");
// }

// void glitch(sil::Image image)
// {
//     sil::Image imageGlitch {image};
//     int width {image.width()};
//     int nbr_de_glitch {random_int(30,200)};
//     int height {image.height()};
//     int count{0};
//     //int x0_glitch {random_int(0,width-20)};
//     //int y0_glitch {random_int(0,height-20)};
//     //int lenght_glitch {random_int(6,10)};
//     //int thinckness_glitch {random_int(1,6)};
//     {
//     for (int x{0}; x < image.width(); x++)
//         for (int y{0}; y < image.height(); y++)
//         {
//             int isPixelGlitch {random_int(0,10)};
//             if (isPixelGlitch == 1 && imageGlitch.pixel(x, y).r == image.pixel(x, y).r && imageGlitch.pixel(x, y).b == image.pixel(x, y).b && imageGlitch.pixel(x, y).g == image.pixel(x, y).g)
//             // si le pixel doit glitcher et qu'il n'a pas encore été changé
//             {
//                 int lenght_glitch {random_int(6,10)};
//                 int thinckness_glitch {random_int(1,6)};
//                 int x0_glitch {x};
//                 int y0_glitch {y};

//                 if(x0_glitch < width/2 && y0_glitch < height/2) //si glitch est en bas-gch
//                 {
//                     for (int longu {0} ; longu < lenght_glitch ; longu ++ ) // travaille sur la longuere 
//                     {
//                         for (int larg {0}; larg < thinckness_glitch; larg ++) // travaille sur la largeure
//                         {
//                             imageGlitch.pixel(x0_glitch+longu, y0_glitch+larg).r = image.pixel(width - longu, height-y0_glitch-larg).r;
//                             imageGlitch.pixel(x0_glitch+longu, y0_glitch+larg).g = image.pixel(width - longu, height-y0_glitch-larg).g;
//                             imageGlitch.pixel(x0_glitch+longu, y0_glitch+larg).b = image.pixel(width - longu, height-y0_glitch-larg).b;
//                         }

//                     }
//                 }
//                 else if(x0_glitch < width/2 && y0_glitch > height/2) // si glitch est en haut-gch
//                 {
//                     for (int longu {0} ; longu < lenght_glitch ; longu ++) // travaille sur la longuere 
//                     {
//                         for (int larg {0}; larg < thinckness_glitch; larg ++) // travaille sur la largeure
//                         {
//                             imageGlitch.pixel(x0_glitch+longu, y0_glitch-larg).r = image.pixel(width - longu, y0_glitch+larg).r;
//                             imageGlitch.pixel(x0_glitch+longu, y0_glitch-larg).g = image.pixel(width - longu, y0_glitch+larg).g;
//                             imageGlitch.pixel(x0_glitch+longu, y0_glitch-larg).b = image.pixel(width - longu, y0_glitch+larg).b;
//                         }
//                     }
//                 }
//                 else if(x0_glitch > width/2 && y0_glitch < height/2) //si glitch en bas-drt
//                     for (int longu {0} ; longu < lenght_glitch ; longu ++ ) // travaille sur la longuere 
//                 {
//                         for (int larg {0}; larg < thinckness_glitch; larg ++) // travaille sur la largeure
//                     {
//                         {
//                             imageGlitch.pixel(width-x0_glitch-longu, y0).r = image.pixel(x0_glitch+longu, height-y0_glitch-larg).r;
//                             imageGlitch.pixel(width-x0_glitch-longu, y0).b = image.pixel(x0_glitch+longu, height-y0_glitch-larg).b;
//                             imageGlitch.pixel(width-x0_glitch-longu, y0).g = image.pixel(x0_glitch+longu, height-y0_glitch-larg).g;
//                         }
//                     }
//                 }
//             else if(x0_glitch > width/2 && y0_glitch > height/2) //haut-drt
//             {

//             }
//         }
//     }
// } 

void glitch (sil::Image image)
{
    sil::Image imageGlitch {image};
    int width {image.width()};
    int height {image.height()};
    int nbr_de_glitch {random_int(70,200)};
    {
    for (int count {0}; count < nbr_de_glitch; count++)
        int x0_glitch {random_int(0,width)};
        int y0_glitch {random_int(0,height)};
        int lenght_glitch {random_int(2,50)};
        int thinckness_glitch {random_int(1,10)};
        int x0_a_recup {random_int(0,width - lenght_glitch+1)};
        int y0_a_recup {random_int(0,height - thinckness_glitch+1)};
        
        for (int xi{0}; xi < lenght_glitch ; xi++)
        {
            for (int yi{0}; yi < thinckness_glitch; yi++)
            {
                if (x0_glitch + xi < width && y0_glitch + yi < height)
                 {
                    imageGlitch.pixel(x0_glitch+xi, y0_glitch+yi).r = image.pixel(x0_a_recup+xi, y0_a_recup+yi).r;
                    imageGlitch.pixel(x0_glitch+xi, y0_glitch+yi).g = image.pixel(x0_a_recup+xi, y0_a_recup+yi).g;
                    imageGlitch.pixel(x0_glitch+xi, y0_glitch+yi).b = image.pixel(x0_a_recup+xi, y0_a_recup+yi).b;
                 }
            }
        }
    }
    imageGlitch.save("output/ex16glitch.png");
}

// Exercice 17 : Tramage

// void tramage(sil::Image photo)
// {
//     const int bayer_n = 4; 
//     float bayer_matrix_4x4[][bayer_n] = { 
//         { -0.5, 0, -0.375, 0.125 }, 
//         { 0.25, -0.25, 0.375, - 0.125 }, 
//         { -0.3125, 0.1875, -0.4375, 0.0625 }, 
//         { 0.4375, -0.625 , 0.3125, -0.1875 }, 
//         };
//     float NewColor {+255*(bayer_matrix_4x4(x*bayer_n))};
// }

int main()
{
    //set_random_seed(0);
    sil::Image logo{"images/logo.png"};
    sil::Image imagefinal{500/*width*/, 500/*height*/};
    sil::Image photo{"images/photo_faible_contraste.jpg"};
    sil::Image photoc{"images/photo.jpg"};
    sil::Image result {345, 300};
//    onlyGreen(logo);
//    blueAndRedReverse(logo);
//    blackAndWhite(logo);
//    inverteColor(logo);
//    degrader();
//    miroir(logo);
//    imageBruit(logo);
//    rotation90(logo,result); //attention ne fonctionne pas
//    RGBsplit(logo);
//    luminosite(photoc);
//    disque();
//    cercle(50);
//    mosaique1(logo);
//    mosaique2(logo);
//    mosaique_miroir(logo);
    return 0;
}
