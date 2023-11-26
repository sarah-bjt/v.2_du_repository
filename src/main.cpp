#include <sil/sil.hpp>
#include "random.hpp"
#include <cmath>
#include <iomanip>
#include <numbers>
#include <math.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
#include <complex>
#include <glm/gtx/matrix_transform_2d.hpp>


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

void blueAndRedReverse(sil::Image image)
{
    for(glm::vec3& color : image.pixels())
    {
        std::swap(color.r, color.b);
    }
        image.save("output/ex02blueAndRedReverse.png");
}

// Exercice 3 : Noir & Blanc

void blackAndWhite (sil::Image& image)
{
    for (glm::vec3& color : image.pixels())
    {
        float const moy {(color.r+color.b+color.g)/3};
        color = glm::vec3{moy};
    }
}

// Exercice 4 : Négatif

void inverteColor (sil::Image image)
{
    for (glm::vec3& color : image.pixels())
    {
        color = 1.f - color;
    }
    image.save("output/ex04inverteColor.png");    
}

// Exercice 5 : Dégradé

void degrader ()
{
    sil::Image image{500/*width*/, 200/*height*/};
    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            float couleur  = static_cast<float>(x)/image.width();
            image.pixel(x,y) = glm::vec3(couleur); 
        }
    }
    image.save("output/ex05degrader.png");    
}

// Exercice 6 : Miroir


void miroir(sil::Image image)
{
    sil::Image image2 {image};
    for (int x{0}; x < image2.width(); ++x)
    {
        for (int y {0}; y < image2.height(); ++y)
        {
            float inverse_x {image2.width() - 1.f - x};
            image.pixel(x, y) = image2.pixel(inverse_x, y);
        }
    }
    image.save("output/ex06miroir.png");
}

// Exercice 7 : Image bruité

void Bruit_vSarah (sil::Image image, float taux_de_bruit)
{
    for (glm::vec3& color : image.pixels())
    {
        float rand{random_float(0.f, 1.f)};
        if (rand < taux_de_bruit)
        {
            color.r =  random_float(0, 1);
            color.b =  random_float(0, 1);
            color.g =  random_float(0, 1);
        }
    }
    image.save("output/ex07bruit_vSarah.png");    
}

void Bruit_vAgathe (sil::Image image)
{
    for(int i{0}; i < 20000; i++)
    {
        int x {random_int(0, image.width())};
        int y {random_int(0, image.height())};
        image.pixel(x, y).r = random_float(0,1);
        image.pixel(x, y).b = random_float(0,1);
        image.pixel(x, y).g = random_float(0,1);
    }
    image.save("output/ex07bruit_vAgathe.png");
}


// Exercice 8 : RGB split

void RGBsplit (sil::Image image,int offset_number)
{
    sil::Image copy {image.width(),image.height()};
    int offset{image.width()/offset_number};
    for (int x{0}; x < image.width()-offset; x++) // pour le rouge vers la drt
    {
        for (int y{0}; y < image.height(); y++)
        {
            copy.pixel(x+offset, y).r = image.pixel(x,y).r;
        }
    }
    for (int x{(offset)}; x< image.width(); x++) // pour le bleu vers la gch
    {
        for (int y{0}; y < image.height(); y++)
        {
            copy.pixel(x - (offset), y).b = image.pixel(x,y).b;
        }
    }
    for (int x{}; x< image.width(); x++) // pour le vert
    {
        for (int y{0}; y < image.height(); y++)
        {
            copy.pixel(x , y).g = image.pixel(x,y).g;
        }
    }
    copy.save("output/ex08RGBsplit.png");
}

// Exercice 9 : Luminosité

void luminosite (sil::Image image)
{

    for (glm::vec3& color : image.pixels())
    {
        color = glm::pow(color, glm::vec3{0.6});
    }
    image.save("output/ex09luminosite.png");
}

// Exercice 10 : Disque

void disque ()
{
    sil::Image image{500/*width*/, 500/*height*/};
    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            if( pow((x-image.width()/2),2)+pow((y-image.height()/2),2)< pow(200,2) )
            {
                image.pixel(x,y) = glm::vec3(1); 
            }
        }
    }
    image.save("output/ex10disque.png");
}

// Exercice 11 : Cercle
void cercle (int thickness)
{
    sil::Image image{500/*width*/, 500/*height*/};
    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            float const distance{std::pow((x-250.f),2.f)+std::pow((y-250.f),2.f)};
            if (distance< pow(200,2) && distance> pow(200-thickness,2) )
            {
                image.pixel(x,y) = glm::vec3(1); 
            }
        }
    }
    image.save("output/ex11cercle.png");
}
// Exercice 12 : Rosace

void dessineCercle( sil::Image& image, float x0 , float y0 , float rayon, float thickness)
{
    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height() ; y++)
        {
        if (pow((x-x0),2)+pow((y-y0),2)< pow(rayon,2) && pow((x-x0),2)+pow((y-y0),2)> pow(rayon-thickness,2) )
                { 
                    image.pixel(x,y) = glm::vec3(1); 
                }
        }        
    }
}

void rosace(sil::Image image)
{
    int width {image.width()};
    int half_width {width/2};
    int height {image.height()};
    int half_height {height/2};
    float rayon {100.f};
    float epaisseur {5.f};

    dessineCercle (image, half_width, half_height ,rayon,epaisseur); //centre
    int nb_circles{6};
    for(int i {0}; i < nb_circles; ++i)
    {
        dessineCercle (image, half_height +(rayon - epaisseur)*std::cos((i*M_PI*2)/nb_circles), half_width+(rayon - epaisseur)*std::sin((i*M_PI*2)/nb_circles),rayon,epaisseur);
    }
    image.save("output/ex12rosace.png");
}

// Exercice 13 : Mosaïque 

void mosaique1(sil::Image image)
{
    sil::Image image2 {image.width()*5, image.height()*5};
    for (int x{0}; x < image.width(); ++x)
    {
        for (int y{0}; y < image.height(); ++y)
        {
            for (int i{0}; i < 5; ++i)
            {
                for(int j{0}; j < 5; ++j)
                { 
                    image2.pixel(x*i, y*j) = image.pixel(x, y);
                }
            }
        }
    }
    image2.save("output/ex13mosaique01.png");
}


void mosaique2(sil::Image image)
{
    sil::Image image2 {image.width()*5, image.height()*5};
    for (int x{0}; x < image.width(); ++x)
    {
        for (int y{0}; y < image.height(); ++y)
        {
            for (int i{0}; i < 5; ++i)
            {
            for (int j{0}; j < 5; ++j)
                {
                    image2.pixel(x+i*image.width(), y+j*image.height()) = image.pixel(x, y);
                }
            }
        }
    }
    image2.save("output/ex13mosaique02.png");
}

// Exercice 14 : Mosaïque miroir

void mosaique_miroir(sil::Image image)
{
    sil::Image image2 {image.width()*5, image.height()*5};

    for (int x{0}; x < image2.width(); x += 1)
    {
        for (int y{0}; y < image2.height(); y += 1)
        {
            int NewX {x%image.width()};
            int NewY {y%image.height()};
            if ((x/image.width()) % 2 == 1)
            {
                NewX = {image.width() - 1 - NewX} ;
            }
            if ((y/image.height()) % 2 == 1)
            {
               NewY = {image.height() - 1 - NewY};
            }
            image2.pixel(x, y) = image.pixel(NewX, NewY);
        }
    }
    image2.save("output/ex14MosaiqueMiroir.png");
}

// Exercice 15 : Glitch

void glitch (sil::Image image)
{
    sil::Image imageGlitch {image};
    int width {image.width()};
    int height {image.height()};
    int nbr_de_glitch {random_int(70,200)};
    for (int count {0}; count < nbr_de_glitch; count++)
    {
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
                    imageGlitch.pixel(x0_glitch+xi, y0_glitch+yi) = image.pixel(x0_a_recup+xi, y0_a_recup+yi);
                 }
            }
        }
    }
    imageGlitch.save("output/ex15glitch.png");
}

// Exercice 16 : Fractale 

void fractale (sil::Image image)
{
   for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        { 
            std::complex<float> c {((4*static_cast<float>(x))/500)- 2  ,((4*static_cast<float>(y))/500)-2};
            std::complex<float> z {0,0};
            int count {0};
            do {
                z = z * z + c;
                count ++;

            } while (std::abs(z) < 2 && count< 50);
            if (std::abs(z) >= 2)
            {
                image.pixel(x, y) = glm::vec3(0 + count/45.f);
            }
            else 
            {
                image.pixel(x, y) = glm::vec3(1);
            }
        } 
    }  
    image.save("output/ex16fractale.png");
}


// Exercice 17 : Tramage

void tramage(sil::Image& image)
{
    blackAndWhite(image);


    const int bayer_n = 4;

    float bayer_matrix_4x4[][bayer_n] = { 
        { -0.5, 0, -0.375, 0.125 }, 
        { 0.25, -0.25, 0.375, - 0.125 }, 
        { -0.3125, 0.1875, -0.4375, 0.0625 }, 
        { 0.4375, -0.625 , 0.3125, -0.1875 } };

    for (int y = 0; y < image.height(); y++)
    { 
        for (int x = 0 ; x < image.width(); x++)
        {
            float orig_color = image.pixel(x, y).r;
            float bayer_value = bayer_matrix_4x4[y % bayer_n][x % bayer_n]; 
            float output_color = orig_color + (1 * bayer_value);

            if (output_color < 0.5f)
            { 
                image.pixel(x,y) = glm::vec3(0);
            }
            else
            {
                image.pixel(x,y) = glm::vec3(1);
            }
        } 
    }
    image.save("output/ex17tramage.png");
    
}
//  Exercice 18 : vortex

glm::vec2 rotated(glm::vec2 point, glm::vec2 center_of_rotation, float angle)
{
    return glm::vec2{glm::rotate(glm::mat3{1.f}, angle) * glm::vec3{point - center_of_rotation, 0.f}} + center_of_rotation;
}

void vortex_ptNoir (sil::Image image)     
{
    sil::Image imageVortex {image.width(),image.height()};
    int x_centre {image.width()/2};
    int y_centre {image.height()/2};
    int width {image.width()};
    int height {image.height()};

    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            double distance_centre { pow( pow((x- x_centre),2) + pow((y - y_centre),2) , 0.5 )};
            double  longueur_max { pow( pow(width,2) + pow( height,2) , 0.5 ) };
            glm::vec2 nouveau_point { rotated( glm::vec2{x,y}, {x_centre,y_centre}, 4*M_PI*(distance_centre/longueur_max))};
            if ( nouveau_point.x < width && nouveau_point.x > 0 && nouveau_point.y < height && nouveau_point.y > 0 )
            {
                imageVortex.pixel(nouveau_point.x, nouveau_point.y).r = image.pixel(x,y).r;
                imageVortex.pixel(nouveau_point.x, nouveau_point.y).b = image.pixel(x,y).b;
                imageVortex.pixel(nouveau_point.x, nouveau_point.y).g = image.pixel(x,y).g;
            }
        }
    }
    imageVortex.save("output/ex18vortex_version_ptNoir.png");
}

void vortex (sil::Image image)
{
    int x_centre {image.width()/2};
    int y_centre {image.height()/2};
    int width {image.width()};
    int height {image.height()};
    sil::Image imageVortex {width,height};

    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            double distance_centre { pow( pow((x- x_centre),2) + pow((y - y_centre),2) , 0.5 )};
            double  longueur_max { pow( pow(width,2) + pow( height,2) , 0.5 )/2 };
            glm::vec2 nouveau_point { rotated( glm::vec2{x,y}, {x_centre,y_centre}, 7*M_PI*(distance_centre/longueur_max))};
            if ( nouveau_point.x < width && nouveau_point.x > 0 && nouveau_point.y < height && nouveau_point.y > 0 )
            {
                imageVortex.pixel(x,y) = image.pixel(nouveau_point.x, nouveau_point.y);
            }
            else 
            {
                imageVortex.pixel(x,y) = glm::vec3(0);
            }
        }
    }
    imageVortex.save("output/ex18vortex.png");
}

// Exercice 19 : Normalisation de l'histogramme 

void normalisationHistogramme (sil::Image image)
{
    float low_brightness {1};
    float hight_brightness {0};
    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            float brightness_value = (image.pixel(x,y).r + image.pixel(x,y).b + image.pixel(x,y).g)/3;
            if (brightness_value >= hight_brightness)
            {
                hight_brightness = brightness_value;
            }
            else if (brightness_value <= low_brightness)
            {
                low_brightness = brightness_value;
            }
        } 
    }
    for (glm::vec3& color : image.pixels())
    {
            color = (color - low_brightness) / (hight_brightness - low_brightness) ;
    } 
    image.save("output/ex19normalisationHistogramme.png"); 
}



// Exercice 20 : Convolutions

void convolutions(sil::Image image)
{
    sil::Image image2 {image};

    float kernel[3][3] = {{ 1.f/9.f, 1.f/9.f, 1.f/9.f }, 
                          { 1.f/9.f, 1.f/9.f, 1.f/9.f }, 
                          { 1.f/9.f, 1.f/9.f, 1.f/9.f }};

        for (int x {0}; x < image2.width(); x += 1)
    {
        for (int y {0}; y < image2.height(); y += 1)
        {
            glm::vec3 moy {};

            for (int x_offset {-1}; x_offset < 2; x_offset++)
            {
                for (int y_offset {-1}; y_offset < 2; y_offset++)
                {
                    if (x < image2.width()-1 && x > 0 && y < image2.height()-1 && y > 0)
                    {
                        moy += image.pixel(x + x_offset, y + y_offset)*kernel[x_offset+1][y_offset+1];
                    }
                    else
                    {
                        moy += glm::vec3(0);
                    }
                }
            }
            image2.pixel(x, y) = moy;
        }
    }
    image2.save("output/ex20convolutions.png");
};

// Exercice 21 : Netteté, contours, ect

void emboss(sil::Image image)
{
    sil::Image image2 {image};

float kernel[3][3] = {{ -2.f, -1.f, 0.f }, 
{ -1.f, 1.f, 1.f }, 
{ 0.f, 1.f, 2.f }};

for (int x {0}; x < image2.width(); x += 1)
{
        for (int y {0}; y < image2.height(); y += 1)
{
            glm::vec3 moy {};

            for (int x_offset {-1}; x_offset < 2; x_offset++)
{
                for (int y_offset {-1}; y_offset < 2; y_offset++)
{
                    if (x < image2.width()-1 && x > 0 && y < image2.height()-1 && y > 0)
                    {
                        moy += image.pixel(x + x_offset, y + y_offset)*kernel[x_offset+1][y_offset+1];
}
                    else
                    {
                        moy += glm::vec3(0);
                    }
                }
            }
            image2.pixel(x, y) = moy;
        }
    }
    image2.save("output/ex21emboss.png");
}

// Exercice 22 : Outline

void outline(sil::Image image)
{
    sil::Image image2 {image};

    float kernel[3][3] = {{ -1.f, -1.f, -1.f }, 
                          { -1.f, 8.f, -1.f }, 
                          { -1.f, -1.f, -1.f }};

   for (int x {0}; x < image2.width(); x += 1)
    {
        for (int y {0}; y < image2.height(); y += 1)
        {
            glm::vec3 moy {};

            for (int x_offset {-1}; x_offset < 2; x_offset++)
            {
                for (int y_offset {-1}; y_offset < 2; y_offset++)
                {
                    if (x < image2.width()-1 && x > 0 && y < image2.height()-1 && y > 0)
                    {
                        moy += image.pixel(x + x_offset, y + y_offset)*kernel[x_offset+1][y_offset+1];
                    }
                    else
                    {
                        moy += glm::vec3(0);
                    }
                }
            }
            image2.pixel(x, y) = moy;
        }
    }
    image2.save("output/ex22outline.png");
}

// Exercice 23 : Sharpen

void sharpen(sil::Image image)
{
    sil::Image image2 {image};

    float kernel[3][3] = {{ 0.f, -1.f, 0.f }, 
                          { -1.f, 5.f, -1.f }, 
                          { 0.f, -1.f, 0.f }};

   for (int x {0}; x < image2.width(); x += 1)
    {
        for (int y {0}; y < image2.height(); y += 1)
        {
            glm::vec3 moy {};

            for (int x_offset {-1}; x_offset < 2; x_offset++)
            {
                for (int y_offset {-1}; y_offset < 2; y_offset++)
                {
                    if (x < image2.width()-1 && x > 0 && y < image2.height()-1 && y > 0)
                    {
                        moy += image.pixel(x + x_offset, y + y_offset)*kernel[x_offset+1][y_offset+1];
                    }
                    else
                    {
                        moy += glm::vec3(0);
                    }
                }
            }
            image2.pixel(x, y) = moy;
        }
    }
    image2.save("output/ex23sharpen.png");
}



int main()
{
    set_random_seed(0);
    sil::Image logo{"images/logo.png"};
    sil::Image imageNoir_500_500{500, 500};
    sil::Image photo_faible{"images/photo_faible_contraste.jpg"};
    sil::Image photo{"images/photo.jpg"};

//    onlyGreen(logo);
//    blueAndRedReverse(logo);

// {
//     sil::Image copie{logo};
//     blackAndWhite(logo);
//     logo.save("output/ex03blackAndWhite.png");
// }

//    inverteColor(logo);
//    degrader();
//    miroir(logo);
//    Bruit_vSarah(logo, 0.28);
//    Bruit_vAgathe(logo);
//    RGBsplit(logo, 7);
//    luminosite(photo);
//    disque();
//    cercle(50);
//    rosace (imageNoir_500_500);
//    mosaique1(logo);
//    mosaique2(logo);
//    mosaique_miroir(logo);
//    glitch(logo);
//    fractale(imageNoir_500_500);

// {
//     sil::Image copie{photo};
//     blackAndWhite(photo);
//     photo.save("output/ex17avant_tramage.png");
// }
//    tramage(photo);

//    vortex(logo);
//    vortex_ptNoir(logo);
//    normalisationHistogramme(photo_faible);
   convolutions(logo);
   emboss(logo);
   outline(logo);
   sharpen(logo);
    return 0;
}