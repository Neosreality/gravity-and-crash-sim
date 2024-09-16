#include <stdio.h>
#include <math.h> // sqrt işlevi için

#define ZEMIN_SEVIYESI 0
#define FAIL 0
#define SUCCESS 1
#define GRAVITY_POSTIVE 9.81
#define GRAVITY_NEGATIVE -9.81

typedef struct
{
    float x, y, z;
} Top;

// Global değişkenler
Top toplar[] = {
    {3, 2, -1},
    {3, 2, 1},
    {3, 2, 0},
    {4, 5, 2},
    {1, 0, -3}};
int top_sayisi = sizeof(toplar) / sizeof(Top);

static void top_kontrol(Top nesne)
{
    // Bu fonksiyon kullanılmıyor
}

void kontrol(Top nesne)
{
    if (nesne.z >= ZEMIN_SEVIYESI)
    {
        printf("Topun durumu: Havada %f konumunda\n", nesne.z);
    }
    else
    {
        printf("Topun durumu: Zemin üzerinde %f konumunda\n", nesne.z);
    }
}

void sure_bul(Top nesne)
{
    float GRAVITY = (nesne.y >= ZEMIN_SEVIYESI) ? GRAVITY_POSTIVE : GRAVITY_NEGATIVE;
    float sure = nesne.y / GRAVITY;
    printf("Topun düşme süresi: %f saniye\n", sure);

    if (sure <= 5)
    {
        printf("Top: Ezik\n");
    }
    else
    {
        printf("Top: İyisin\n");
    }
}

void mesafe_bul(Top nesne)
{
    // 3D mesafe bulma formülü: sqrt(x^2 + y^2 + z^2) 0,0,0 göre
    float mesafe = sqrt(nesne.x * nesne.x + nesne.y * nesne.y + nesne.z * nesne.z);
    printf("Topun mesafe: %f metre\n", mesafe);
}

void hareket_et()
{
    for (int a = 0; a < top_sayisi; a++)
    {
        toplar[a].x += 2;
        toplar[a].y += 2;
        toplar[a].z += 2;
    }
}

int main()
{

    for (int i = 0; i < top_sayisi; i++)
    {
        printf("Top %d:\n", i + 1);
        kontrol(toplar[i]);
        sure_bul(toplar[i]);
        mesafe_bul(toplar[i]); // mesafe_bul fonksiyonunu her top için çağır
        hareket_et(toplar[i]);
        printf("X,Y,Z konumları: %f,%f,%f\n", toplar[i].x, toplar[i].y, toplar[i].z); // topların hareket etmesini sağlamak için
        printf("\n");
    }

    return 0;
}
