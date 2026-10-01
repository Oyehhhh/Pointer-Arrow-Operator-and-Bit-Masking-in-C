#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define LAZER_BITI 0       
#define SOGUTMA_BITI 1     
#define HATA_BITI 7        


struct LazerKafasi {
    int x_koordinat;
    int y_koordinat;
    int sicaklik;
    unsigned char donanim_yazmaci; 
};


void lazer_kafasini_yonet(struct LazerKafasi *cihaz, int hedef_x, int hedef_y, int anlik_sicaklik) {
    
    
    
    cihaz ->sicaklik = anlik_sicaklik;
    
    
    
    if (cihaz ->sicaklik > 80){
        cihaz->donanim_yazmaci = cihaz->donanim_yazmaci | (1 << 1);
        cihaz->donanim_yazmaci = cihaz->donanim_yazmaci & ~(1 << 0);
        return;
    }
    
    
    if (cihaz->sicaklik <= 80){
        cihaz->donanim_yazmaci = cihaz->donanim_yazmaci | (1 << 0);
        cihaz->donanim_yazmaci = cihaz->donanim_yazmaci & ~(1 << 1);
        cihaz->x_koordinat = hedef_x;
        cihaz->y_koordinat = hedef_y;
    }

}

int main() {
    
    struct LazerKafasi asml_lazer = {0, 0, 25, 0};

    printf("--- SENARYO 1: Normal Calisma (Sıcaklık 45 derece) ---\n");
    lazer_kafasini_yonet(&asml_lazer, 100, 200, 45);
    printf("Lazer Koordinatları -> X: %d, Y: %d\n", asml_lazer.x_koordinat, asml_lazer.y_koordinat);
    printf("Donanim Yazmaci (Decimal): %d\n", asml_lazer.donanim_yazmaci); 
    
    printf("\n--- SENARYO 2: Asiri Isinma (Sıcaklık 95 derece) ---\n");
    
    lazer_kafasini_yonet(&asml_lazer, 500, 600, 95);
    printf("Lazer Koordinatları -> X: %d, Y: %d\n", asml_lazer.x_koordinat, asml_lazer.y_koordinat);
    printf("Donanim Yazmaci (Decimal): %d\n", asml_lazer.donanim_yazmaci);
    

    return 0;
}

