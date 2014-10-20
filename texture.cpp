#include "texture.hpp"

void Texture::loadTextures()
{
    glGenTextures(NTEX, textures);

    bmp.loadBmpTexture("textures/hdfront.bmp", textures[HDFRONT]);
    bmp.loadBmpTexture("textures/back.bmp", textures[VEHBACK]);
    bmp.loadBmpTexture("textures/tyre.bmp", textures[TYRE]);
    bmp.loadBmpTexture("textures/tyreTex.bmp", textures[TYRETEX]);
    bmp.loadBmpTexture("textures/military.bmp", textures[MILITARY]);
    bmp.loadBmpTexture("textures/grill.bmp", textures[GRILL]);
    bmp.loadBmpTexture("textures/rside.bmp", textures[RSIDE]);
    bmp.loadBmpTexture("textures/lside.bmp", textures[LSIDE]);
    bmp.loadBmpTexture("textures/hiprside.bmp", textures[HIPRSIDE]);
    bmp.loadBmpTexture("textures/hiplside.bmp", textures[HIPLSIDE]);
    bmp.loadBmpTexture("textures/rfoot.bmp", textures[RFOOT]);
    bmp.loadBmpTexture("textures/lfoot.bmp", textures[LFOOT]);
    bmp.loadBmpTexture("textures/frontPane.bmp", textures[FRONTPANE]);
    bmp.loadBmpTexture("textures/faceleft.bmp", textures[FACELEFT]);
    bmp.loadBmpTexture("textures/faceright.bmp", textures[FACERIGHT]);
    bmp.loadBmpTexture("textures/vehiclebackleft.bmp", textures[BACKLEFT]);
    bmp.loadBmpTexture("textures/vehiclebackright.bmp", textures[BACKRIGHT]);
    bmp.loadBmpTexture("textures/frontright.bmp", textures[FRONTRIGHT]);
    bmp.loadBmpTexture("textures/frontleft.bmp", textures[FRONTLEFT]);
    bmp.loadBmpTexture("textures/bonnetright.bmp", textures[BONNETRIGHT]);
    bmp.loadBmpTexture("textures/bonnetleft.bmp", textures[BONNETLEFT]);
    bmp.loadBmpTexture("textures/bonnetmid.bmp", textures[BONNETMID]);
    bmp.loadBmpTexture("textures/sparetyre.bmp", textures[SPARETYRE]);
    bmp.loadBmpTexture("textures/lightfront.bmp", textures[LIGHTFRONT]);

    bmp.loadBmpTexture("wfar.bmp", textures[WFAR]);
    bmp.loadBmpTexture("wnear.bmp", textures[WNEAR]);
    bmp.loadBmpTexture("wleft.bmp", textures[WLEFT]);
    bmp.loadBmpTexture("wright.bmp", textures[WRIGHT]);
    bmp.loadBmpTexture("wtop.bmp", textures[WTOP]);
    bmp.loadBmpTexture("wbottom.bmp", textures[WBOTTOM]);
}

