
#include "../include/types.h"
#include "../include/msgdata.h"

#define GENDER_CURSOR_MALE    0
#define GENDER_CURSOR_FEMALE  1
#define GENDER_CURSOR_BOTH    2
#define GENDER_CURSOR_NEITHER 3

#define TOUCHTOADVANCE_HIDE    0
#define TOUCHTOADVANCE_SHOW    1
#define TOUCHTOADVANCE_PRESS   2
#define TOUCHTOADVANCE_RELEASE 3

typedef enum HeapID {
    HEAP_ID_DEFAULT,
    HEAP_ID_1,
    HEAP_ID_2,
} HeapID;

typedef struct SaveData {
    BOOL flashChipDetected;
    BOOL saveFileExists;
    BOOL isNewGame;
} SaveData; // size=0x2330C

typedef struct Options {
    u16 textSpeed : 4;
    u16 soundMethod : 2;
    u16 battleStyle : 1;
    u16 battleScene : 1;
    u16 buttonMode : 2;
    u16 frame : 5;
    u16 dummy : 1;
} Options;

typedef struct OVY_MANAGER OVY_MANAGER;

typedef int (*OVY_FUNC)(OVY_MANAGER *manager, int *state);

typedef u32 FSOverlayID;

typedef struct OVY_MGR_TEMPLATE {
    OVY_FUNC init;
    OVY_FUNC exec;
    OVY_FUNC exit;
    FSOverlayID ovy_id;
} OVY_MGR_TEMPLATE;

struct OVY_MANAGER {
    OVY_MGR_TEMPLATE template;
    int exec_state;
    int proc_state;
    void *args;
    void *data;
    u32 unk_20;
    u32 unk_24;
};

typedef struct BgConfig {
    HeapID heapId;
    u16 scrollScheduled;
    u16 bufferTransferScheduled;
} BgConfig;

typedef struct Window {
    BgConfig *bgConfig;
    u8 bgId;
    u8 tilemapLeft;
} Window;

typedef struct SpriteRenderer {
    HeapID heapId;
    u32 numGfxHandlers;
    BOOL hasOamManager;
} SpriteRenderer;                               // size: 0x138

// typedef struct SpriteGfxHandler {
//     SpriteList *spriteList;
//     SpriteResourceHeaderList *spriteHeaderList;                // 4
//     GF_2DGfxResHeader *_2dGfxResHeader;                        // 8
// } SpriteGfxHandler; // size: 0x58

// typedef struct SpriteResourcesHeader {
//     const NNSG2dImageProxy *imageProxy;
//     const NNSG2dCharacterData *charData;
//     const NNSG2dImagePaletteProxy *plttProxy;
//     NNSG2dCellDataBank *cellData;
//     const NNSG2dCellAnimBankData *cellAnim;
//     const NNSG2dMultiCellDataBank *multiCellData;
//     const NNSG2dMultiCellAnimBankData *multiCellAnim;
//     int flag;
//     u8 priority;
// } SpriteResourcesHeader;

// typedef struct SpriteResourceHeaderList {
//     SpriteResourcesHeader *headers;
//     int num;
// } SpriteResourceHeaderList;

// struct SpriteList {
//     Sprite *sprites;                  // 0x000
//     int numSprites;                   // 0x004
//     Sprite **stack;                   // 0x008
//     int stackPointer;                 // 0x00C
//     Sprite dummy;                     // 0x010
//     NNSG2dRendererInstance *renderer; // 0x114
//     void *animBuff;                   // 0x118
//     NNSG2dCellAnimBankData *animBank; // 0x11C
//     u32 flag;                         // 0x120
// };

// typedef struct Sprite {
//     VecFx32 matrix;                                      // 000
//     VecFx32 affineMatrix;                                // 00C
//     VecFx32 scale;                                       // 018
//     u16 rotation;                                        // 024
//     u8 affine;                                           // 026
//     u8 flip;                                             // 027
//     u8 overwrite;                                        // 028
//     u8 palIndex;                                         // 029
//     u8 palOffset;                                        // 02a
//     BOOL mosaic;                                         // 02c
//     GXOamMode mode;                                      // 030
//     u8 drawFlag;                                         // 034
//     u8 animActive;                                       // 035
//     fx32 speed;                                          // 038
//     SpriteList *spriteList;                              // 03c
//     u32 animationData[SPRITE_ANIMATION_DATA_WORD_COUNT]; // 040
//     NNSG2dImageProxy imageProxy;                         // 0b4
//     NNSG2dImagePaletteProxy paletteProxy;                // 0d8
//     SpriteAnimType flag;                                 // 0ec
//     u16 animationNo;                                     // 0f0
//     u8 priority;                                         // 0f2
//     u16 drawPriority;                                    // 0f4
//     NNS_G2D_VRAM_TYPE type;                              // 0f8
//     struct Sprite *prev;                                 // 0fc
//     struct Sprite *next;                                 // 100
// } Sprite;

typedef struct OakSpeechMultichoice {
    u8 unk_0;
    u8 numOptions;
    u8 inPadMode;
    u8 cursorPos;
    u8 flashDelay;
    u8 flashFramesPer;
    u8 pressDelay;
    u8 flashState;
} OakSpeechMultichoice;

typedef enum NameScreenType {
    NAME_SCREEN_PLAYER,
    NAME_SCREEN_POKEMON,
    NAME_SCREEN_BOX,
    NAME_SCREEN_RIVAL,
    NAME_SCREEN_UNK4,
    NAME_SCREEN_GROUP,
    NAME_SCREEN_UNK6,
    NAME_SCREEN_UNK7,
} NameScreenType;

typedef struct NamingScreenArgs {
    NameScreenType kind;
    int playerGenderOrMonSpecies; // monSpecies
    int monForm;
    int maxLen;
    int monGender;
    BOOL noInput;
    String *nameInputString;
    u16 nameInputFlat[20];
    int battleMsgId;
    // PCStorage *pcStorage;
    // Options *options;
    // MenuInputStateMgr *pMenuInputState;
} NamingScreenArgs;

typedef struct OakSpeechData {
    HeapID heapId;
    SaveData *saveData;
    Options *options;
    int state;
    int unk_010;
    OVY_MANAGER *overlayManager;
    BgConfig *bgConfig;
    Window fullScreenMsgWindow;
    Window dialogWindow;
    Window multichoiceMenuButtonWindows[3];
    Window controlTutorialTouchMsgWindow;
    int numMultichoiceOptions;
    int unk_080;
    u8 filler_084[0x4C];
    SpriteRenderer *spriteRenderer;
    // SpriteGfxHandler *spriteGfxHandler;
    u8 *spriteGfxHandler[0x58];
    void *sprites[6];
    u8 filler_0F0[0x10];
    void *msgData;
    int printDialogMsgState;
    int printAndFadeFullScreenTextState;
    u32 textPrinter;
    void *string;
    void *unk_114;
    void *msgFormat;
    u8 filler_11C[0x4];
    NamingScreenArgs *namingScreenArgs_Player;
    NamingScreenArgs *namingScreenArgs_Rival; // leftover from DPPt
    int layerBlendState;
    int layerBlendEv1;
    int layerBlendEv2;
    u16 playerGender;
    u16 genderSelectFrameDefaultPalette;
    u8 filler_138[0x4];
    int frameDelayCounter;
    int playerPicShrinkAnimStep;
    int playerPicShrinkAnimDelay;
    u8 filler_148[0x18];
    OakSpeechMultichoice menuData;
    int genderSelectFrameBlinkTimer;
    int lastInputWasTouch;
    int queuedMsgId;
    u16 oakPicHTranslateState;
    s16 oakPicHTranslatePos;
    void *yesnoMenu;
    int lastChosenGender; // if the player changes their mind
} OakSpeechData;