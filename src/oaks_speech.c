#include "../include/types.h"
#include "../include/oaks_speech_internal.h"
#include "../include/constants/sndseq.h"
#include "../include/constants/species.h"

// In Diamond and Pearl, the player pics were animated.
// Vestiges of that system remain here.
typedef enum OakSpeechPic {
    OAK_SPEECH_PIC_NONE = 0,
    OAK_SPEECH_PIC_OAK = 1,
    OAK_SPEECH_PIC_ETHAN = 2,
    OAK_SPEECH_PIC_LYRA = 6,
} OakSpeechPic;

typedef enum OakSpeechMainState {
    OAK_SPEECH_MAIN_STATE_START_TUTORIAL_MUSIC = 0,
    OAK_SPEECH_MAIN_STATE_WAIT_FADE_IN_TUTORIAL_MENU = 1,
    OAK_SPEECH_MAIN_STATE_PRINT_TUTORIAL_MENU_MESSAGES = 2,
    OAK_SPEECH_MAIN_STATE_TUTORIAL_MENU_HANDLE_INPUT = 3,
    OAK_SPEECH_MAIN_STATE_FADE_OUT_TUTORIAL_MENU = 4,
    OAK_SPEECH_MAIN_STATE_FADE_OUT_TUTORIAL_MENU_BGS = 5,
    OAK_SPEECH_MAIN_STATE_WAIT_FADE_OUT_TUTORIAL_MENU_BGS = 6,
    OAK_SPEECH_MAIN_STATE_FADE_IN_TUTORIAL_MENU = 7,
    OAK_SPEECH_MAIN_STATE_FADE_IN_CONTROL_INFO = 8,
    OAK_SPEECH_MAIN_STATE_WAIT_FADE_IN_CONTROL_INFO = 9,
    OAK_SPEECH_MAIN_STATE_CONTROL_INFO_1 = 11,
    OAK_SPEECH_MAIN_STATE_CONTROL_INFO_2 = 12,
    OAK_SPEECH_MAIN_STATE_CONTROL_INFO_3 = 13,
    OAK_SPEECH_MAIN_STATE_CONTROL_INFO_4 = 14,
    OAK_SPEECH_MAIN_STATE_CONTROL_INFO_5 = 15,
    OAK_SPEECH_MAIN_STATE_CONTROL_INFO_6 = 16,
    OAK_SPEECH_MAIN_STATE_CONTROL_INFO_7 = 17,
    OAK_SPEECH_MAIN_STATE_CONTROL_INFO_8 = 18,
    OAK_SPEECH_MAIN_STATE_CONTROL_INFO_9 = 19,
    OAK_SPEECH_MAIN_STATE_CONTROL_INFO_10 = 20,
    OAK_SPEECH_MAIN_STATE_CONTROL_INFO_11 = 21,
    OAK_SPEECH_MAIN_STATE_CONTROL_INFO_23 = 22,
    OAK_SPEECH_MAIN_STATE_CONTROL_INFO_ASK_UNDERSTOOD = 23,
    OAK_SPEECH_MAIN_STATE_CONTROL_INFO_ASK_UNDERSTOOD_HANDLE_YESNO = 24,
    OAK_SPEECH_MAIN_STATE_CONTROL_INFO_UNDERSTOOD_YES = 27,
    OAK_SPEECH_MAIN_STATE_CONTROL_INFO_UNDERSTOOD_YES_WAIT_FADE = 28,
    OAK_SPEECH_MAIN_STATE_CONTROL_INFO_UNDERSTOOD_NO = 29,
    OAK_SPEECH_MAIN_STATE_FADE_IN_ADVENTURE_INFO = 34,
    OAK_SPEECH_MAIN_STATE_WAIT_FADE_IN_ADVENTURE_INFO = 35,
    OAK_SPEECH_MAIN_STATE_ADVENTURE_INFO_1 = 36,
    OAK_SPEECH_MAIN_STATE_ADVENTURE_INFO_2 = 37,
    OAK_SPEECH_MAIN_STATE_ADVENTURE_INFO_3 = 38,
    OAK_SPEECH_MAIN_STATE_ADVENTURE_INFO_4 = 39,
    OAK_SPEECH_MAIN_STATE_ADVENTURE_INFO_5 = 40,
    OAK_SPEECH_MAIN_STATE_ADVENTURE_INFO_6 = 41,
    OAK_SPEECH_MAIN_STATE_ADVENTURE_INFO_FADE_OUT = 42,
    OAK_SPEECH_MAIN_STATE_WAIT_FADE_OUT_ADVENTURE_INFO = 43,
    OAK_SPEECH_MAIN_STATE_NO_INFO_NEEDED_FADE_IN = 44,
    OAK_SPEECH_MAIN_STATE_WAIT_FADE_IN_NO_INFO_NEEDED = 45,
    OAK_SPEECH_MAIN_STATE_PRINT_TIME_OF_DAY_MSG = 46,
    OAK_SPEECH_MAIN_STATE_SHOW_OAK = 47,
    OAK_SPEECH_MAIN_STATE_WAIT_FADE_IN_OAK = 48,
    OAK_SPEECH_MAIN_STATE_WELCOME_TO_WORLD = 49,
    OAK_SPEECH_MAIN_STATE_SLIDE_OAK_RIGHT = 50,
    OAK_SPEECH_MAIN_STATE_THIS_WORLD_IS_INHABITED = 51,
    OAK_SPEECH_MAIN_STATE_BALL_OPENING_FLASH = 52,
    OAK_SPEECH_MAIN_STATE_APPEAR_MARILL = 53,
    OAK_SPEECH_MAIN_STATE_MARILL_CRY = 54,
    OAK_SPEECH_MAIN_STATE_WAIT_MARILL_CRY = 55,
    OAK_SPEECH_MAIN_STATE_WE_LIVE_ALONGSIDE = 56,
    OAK_SPEECH_MAIN_STATE_HIDE_MARILL = 57,
    OAK_SPEECH_MAIN_STATE_WAIT_AFTER_HIDE_MARILL = 58,
    OAK_SPEECH_MAIN_STATE_SLIDE_OAK_LEFT = 59,
    OAK_SPEECH_MAIN_STATE_TELL_ME_ABOUT_YOURSELF = 60,
    OAK_SPEECH_MAIN_STATE_ARE_YOU_A_GENDER = 61,
    OAK_SPEECH_MAIN_STATE_WAIT_FADE_OUT_TO_ASK_GENDER = 62,
    OAK_SPEECH_MAIN_STATE_SETUP_GENDER_SELECT_MENU = 63,
    OAK_SPEECH_MAIN_STATE_WAIT_FADE_IN_GENDER_SELECT_MENU = 64,
    OAK_SPEECH_MAIN_STATE_GENDER_SELECT_MENU_HANDLE_INPUT = 65,
    OAK_SPEECH_MAIN_STATE_PREPARE_ASK_CONFIRM_GENDER = 66,
    OAK_SPEECH_MAIN_STATE_ASK_CONFIRM_GENDER = 67,
    OAK_SPEECH_MAIN_STATE_CONFIRM_GENDER_YESNO_INIT_MENU = 68,
    OAK_SPEECH_MAIN_STATE_CONFIRM_GENDER_YESNO_HANDLE_INPUT = 69,
    OAK_SPEECH_MAIN_STATE_CONFIRM_GENDER_YESNO_HANDLE_RESULT = 70,
    OAK_SPEECH_MAIN_STATE_CONFIRM_GENDER_NO_WAIT_FADE_OUT = 71,
    OAK_SPEECH_MAIN_STATE_CONFIRM_GENDER_NO_WAIT_FADE_IN = 72,
    OAK_SPEECH_MAIN_STATE_CONFIRM_GENDER_YES = 93,
    OAK_SPEECH_MAIN_STATE_PROMPT_NAME_DELAY_BEFORE = 94,
    OAK_SPEECH_MAIN_STATE_PROMPT_NAME_LAUNCH_NAMING_SCREEN = 95,
    OAK_SPEECH_MAIN_STATE_PROMPT_NAME_RESTORE_GRAPHICS_AFTER = 96,
    OAK_SPEECH_MAIN_STATE_CONFIRM_NAME_YESNO_INIT_MENU = 97,
    OAK_SPEECH_MAIN_STATE_CONFIRM_NAME_YESNO_HANDLE_INPUT = 98,
    OAK_SPEECH_MAIN_STATE_CONFIRM_NAME_YESNO_HANDLE_RESULT = 99,
    OAK_SPEECH_MAIN_STATE_CONFIRM_NAME_YES = 100,
    OAK_SPEECH_MAIN_STATE_CONFIRM_NAME_YES_WAIT_FADE_OUT = 101,
    OAK_SPEECH_MAIN_STATE_CONFIRM_NAME_YES_WAIT_FADE_IN = 102,
    OAK_SPEECH_MAIN_STATE_YOUR_ADVENTURE_UNFOLDS = 103,
    OAK_SPEECH_MAIN_STATE_FADE_OUT_FROM_LAST_OAK_MESSAGE = 110,
    OAK_SPEECH_MAIN_STATE_WAIT_FADE_OUT_FROM_LAST_OAK_MESSAGE = 111,
    OAK_SPEECH_MAIN_STATE_FADE_IN_TO_SHRINK_ANIM = 120,
    OAK_SPEECH_MAIN_STATE_WAIT_FADE_IN_TO_SHRINK_ANIM = 121,
    OAK_SPEECH_MAIN_STATE_NOP_BEFORE_SHRINK_ANIM = 123,
    OAK_SPEECH_MAIN_STATE_INIT_SHRINK_ANIM_STATE = 124,
    OAK_SPEECH_MAIN_STATE_DELAY_BEFORE_SHRINK_ANIM = 125,
    OAK_SPEECH_MAIN_STATE_RUN_SHRINK_ANIM = 126,
} OakSpeechMainState;

void ToggleBgLayer(u8 bgId, u8 toggle);
void sub_02004EC4(int a0, u16 a1, int a2);
void StopBGM(u16 sndseq, int a1);

// static void OakSpeech_VBlankCB(void *cbArg);
// static void OakSpeech_InitBgs(OakSpeechData *data);
// static void OakSpeech_CleanupBgs(OakSpeechData *data);
// static void OakSpeech_InitMsgPrinter(OakSpeechData *data);
// static void OakSpeech_CleanupMsgPrinter(OakSpeechData *data);
// static BOOL OakSpeech_BlendLayer(OakSpeechData *data, int param, BOOL isFadeOut);
// static BOOL OakSpeech_WaitFrames(OakSpeechData *data, int delay);
// static void OakSpeech_FillBgLayerWithPalette(OakSpeechData *data, int bgId, int palette);
// static BOOL OakSpeech_PrintDialogMsg(OakSpeechData *data, int msgNum, int waitButtonMode);
// static BOOL OakSpeech_PrintAndFadeFullScreenText(OakSpeechData *data, int msgNum, int kind, int y, int height);
// static BOOL OakSpeech_PrintAndFadeCenteredFullScreenText(OakSpeechData *data, int msgNum, int kind);
// static void OakSpeech_PrintMultichoiceMenu(OakSpeechData *data, int msg1, int msg2, int msg3, int numChoices);
// static void OakSpeech_FreeWindows(OakSpeechData *data);
// static void OakSpeech_LoadButtonTutorialGfx(OakSpeechData *data);
// static void OakSpeech_SetButtonTutorialScreenLayout(OakSpeechData *data, int a1);
// static void OakSpeech_DrawPicOnBgLayer(OakSpeechData *data, int a1, int a2);
// static void ov53_021E67C4(OakSpeechData *data, int a1);
// static void ov53_021E6824(OakSpeechData *data, int a1);
// static void OakSpeech_InitMultichoiceMenu(OakSpeechMultichoice *dest, int a1);
// static void OakSpeech_InitMultichoiceMenuWithFrameFlash(OakSpeechData *data, int a1);
// static int OakSpeech_MultichoiceMenuHandleInputVertical(OakSpeechData *data, int a1);
// static u16 OakSpeech_AdditiveTransformColor(u16 a0, s8 a1);
// static void OakSpeech_BlinkHighlightedGenderFrame(OakSpeechData *data, int a1);
// static void OakSpeech_StopHighlightedGenderFrameBlink(OakSpeechData *data);
// static BOOL OakSpeech_GenderSelectHandleInput(OakSpeechData *data);
// static void OakSpeech_InitPlayerPicShrinkAnim(OakSpeechData *data);
// static BOOL OakSpeech_PlayerPicShrinkAnim(OakSpeechData *data);
// static int OakSpeech_GetTimeOfDayIntroMsg(void);
// static BOOL OakSpeech_TranslateOakPicHorizontally(OakSpeechData *data, int bgId, int direction);
// static BOOL OakSpeech_DoMainTask(OakSpeechData *data);
// static void OakSpeech_CreateMultichoiceYesNoMenu(OakSpeechData *data);
// static void OakSpeech_ClearBgLayer0TopBottomAndCommit(OakSpeechData *data);
// static void OakSpeech_ShowTutorialTouchMsg(OakSpeechData *data);
// static void OakSpeech_HideTutorialTouchMsg(OakSpeechData *data);
// static void OakSpeech_TouchToAdvanceButtonAction(OakSpeechData *data, int a1);
// static BOOL OakSpeech_IsTouchToAdvanceButtonDepressed(OakSpeechData *data);
// static BOOL OakSpeech_IsTouchToAdvanceButtonActive(OakSpeechData *data);
// static void OakSpeech_HandleTouchToAdvanceButton(OakSpeechData *data);

typedef enum {
    GF_PLANE_TOGGLE_OFF,
    GF_PLANE_TOGGLE_ON,
} GFPlaneToggle;

typedef enum GFBgLayer {
    GF_BG_LYR_MAIN_0 = 0,
    GF_BG_LYR_MAIN_1,
    GF_BG_LYR_MAIN_2,
    GF_BG_LYR_MAIN_3,
    GF_BG_LYR_SUB_0,
    GF_BG_LYR_SUB_1,
    GF_BG_LYR_SUB_2,
    GF_BG_LYR_SUB_3,
    GF_BG_LYR_MAIN_CNT = 4,
    GF_BG_LYR_SUB_CNT = 4,
    GF_BG_LYR_MAIN_FIRST = GF_BG_LYR_MAIN_0,
    GF_BG_LYR_SUB_FIRST = GF_BG_LYR_SUB_0,
    GF_BG_LYR_MAX = 8,

    GF_BG_LYR_MAIN_0_F = 1 << (GF_BG_LYR_MAIN_0 - GF_BG_LYR_MAIN_FIRST),
    GF_BG_LYR_MAIN_1_F = 1 << (GF_BG_LYR_MAIN_1 - GF_BG_LYR_MAIN_FIRST),
    GF_BG_LYR_MAIN_2_F = 1 << (GF_BG_LYR_MAIN_2 - GF_BG_LYR_MAIN_FIRST),
    GF_BG_LYR_MAIN_3_F = 1 << (GF_BG_LYR_MAIN_3 - GF_BG_LYR_MAIN_FIRST),
    GF_BG_LYR_SUB_0_F = 1 << (GF_BG_LYR_SUB_0 - GF_BG_LYR_SUB_FIRST),
    GF_BG_LYR_SUB_1_F = 1 << (GF_BG_LYR_SUB_1 - GF_BG_LYR_SUB_FIRST),
    GF_BG_LYR_SUB_2_F = 1 << (GF_BG_LYR_SUB_2 - GF_BG_LYR_SUB_FIRST),
    GF_BG_LYR_SUB_3_F = 1 << (GF_BG_LYR_SUB_3 - GF_BG_LYR_SUB_FIRST),

    GF_BG_LYR_UNALLOC = 0xFF,
} GFBgLayer;

typedef enum YesNoResponse {
    YESNORESPONSE_WAIT = 0,
    YESNORESPONSE_YES,
    YESNORESPONSE_NO,
    YESNORESPONSE_YES_TOUCH,
    YESNORESPONSE_NO_TOUCH,
} YesNoResponse;

typedef struct {
    u8 planeMask:5;
    u8 effect:1;
    u8 _reserve:2;
} GXWndPlane;

typedef enum GXBlendPlaneMask {
    GX_BLEND_PLANEMASK_NONE = 0x0000,
    GX_BLEND_PLANEMASK_BG0 = 0x0001,
    GX_BLEND_PLANEMASK_BG1 = 0x0002,
    GX_BLEND_PLANEMASK_BG2 = 0x0004,
    GX_BLEND_PLANEMASK_BG3 = 0x0008,
    GX_BLEND_PLANEMASK_OBJ = 0x0010,
    GX_BLEND_PLANEMASK_BD = 0x0020
} GXBlendPlaneMask;

typedef enum {
    GX_WND_PLANEMASK_NONE = 0x0000,
    GX_WND_PLANEMASK_BG0 = 0x0001,
    GX_WND_PLANEMASK_BG1 = 0x0002,
    GX_WND_PLANEMASK_BG2 = 0x0004,
    GX_WND_PLANEMASK_BG3 = 0x0008,
    GX_WND_PLANEMASK_OBJ = 0x0010
} GXWndPlaneMask;

enum BgPosAdjustOp {
    // Text layers
    BG_POS_OP_SET_X = 0,
    BG_POS_OP_ADD_X,
    BG_POS_OP_SUB_X,
    BG_POS_OP_SET_Y,
    BG_POS_OP_ADD_Y,
    BG_POS_OP_SUB_Y,

    // Affine layers
    BG_POS_OP_SET_ROT = 0,
    BG_POS_OP_ADD_ROT,
    BG_POS_OP_SUB_ROT,
    BG_POS_OP_SET_XSCALE,
    BG_POS_OP_ADD_XSCALE,
    BG_POS_OP_SUB_XSCALE,
    BG_POS_OP_SET_YSCALE,
    BG_POS_OP_ADD_YSCALE,
    BG_POS_OP_SUB_YSCALE,
    BG_POS_OP_SET_CENTERX,
    BG_POS_OP_ADD_CENTERX,
    BG_POS_OP_SUB_CENTERX,
    BG_POS_OP_SET_CENTERY,
    BG_POS_OP_ADD_CENTERY,
    BG_POS_OP_SUB_CENTERY,
};

#define RGB_BLACK RGB(0, 0, 0)
#define RGB_WHITE RGB(31, 31, 31)

#define SCREEN_MASK_MAIN 1
#define SCREEN_MASK_SUB  2

#define PLAYER_NAME_LENGTH  7
#define POKEMON_NAME_LENGTH 10

#define PLAYER_GENDER_MALE   0
#define PLAYER_GENDER_FEMALE 1

BOOL LONG_CALL OakSpeech_DoMainTask(OakSpeechData *data) {
    debug_printf("In OakSpeech_DoMainTask\n");
    return FALSE;
    /*
    BOOL ret = FALSE;

    switch (data->state) {
    case OAK_SPEECH_MAIN_STATE_START_TUTORIAL_MUSIC:
        ToggleBgLayer(GF_BG_LYR_SUB_2, GF_PLANE_TOGGLE_OFF);
        sub_02004EC4(2, SEQ_GS_POKEMON_THEME, 1);
        StopBGM(SEQ_GS_POKEMON_THEME, 0);
        PlayBGM(SEQ_GS_STARTING);
        data->state = OAK_SPEECH_MAIN_STATE_FADE_IN_TUTORIAL_MENU;
        break;
    case OAK_SPEECH_MAIN_STATE_FADE_IN_TUTORIAL_MENU:
        ov53_021E6824(data, 0);
        OakSpeech_SetButtonTutorialScreenLayout(data, 1);
        ov53_021E67C4(data, 0);
        ToggleBgLayer(GF_BG_LYR_MAIN_3, GF_PLANE_TOGGLE_ON);
        ToggleBgLayer(GF_BG_LYR_MAIN_0, GF_PLANE_TOGGLE_ON);
        ToggleBgLayer(GF_BG_LYR_SUB_0, GF_PLANE_TOGGLE_ON);
        ToggleBgLayer(GF_BG_LYR_SUB_3, GF_PLANE_TOGGLE_ON);
        BeginNormalPaletteFade(0, 1, 1, RGB_BLACK, 6, 1, data->heapId);
        data->state = OAK_SPEECH_MAIN_STATE_WAIT_FADE_IN_TUTORIAL_MENU;
        break;
    case OAK_SPEECH_MAIN_STATE_WAIT_FADE_IN_TUTORIAL_MENU:
        if (IsPaletteFadeFinished() == TRUE && OakSpeech_WaitFrames(data, 40) == TRUE) {
            data->state = OAK_SPEECH_MAIN_STATE_PRINT_TUTORIAL_MENU_MESSAGES;
        }
        break;
    case OAK_SPEECH_MAIN_STATE_PRINT_TUTORIAL_MENU_MESSAGES:
        if (OakSpeech_PrintAndFadeCenteredFullScreenText(data, 07, 2) == TRUE) {
            ToggleBgLayer(GF_BG_LYR_SUB_2, GF_PLANE_TOGGLE_ON);
            data->state = OAK_SPEECH_MAIN_STATE_TUTORIAL_MENU_HANDLE_INPUT;
            OakSpeech_PrintMultichoiceMenu(data, 44, 45, 46, 3);
            data->menuData.inPadMode = 0;
            data->menuData.cursorPos = 0;
        }
        break;
    case OAK_SPEECH_MAIN_STATE_TUTORIAL_MENU_HANDLE_INPUT:
        if (OakSpeech_MultichoiceMenuHandleInputVertical(data, 0) != -1) {
            data->state = OAK_SPEECH_MAIN_STATE_FADE_OUT_TUTORIAL_MENU;
        }
        break;
    case OAK_SPEECH_MAIN_STATE_FADE_OUT_TUTORIAL_MENU:
        if (OakSpeech_PrintAndFadeCenteredFullScreenText(data, 07, 2) == TRUE) {
            OakSpeech_FreeWindows(data);
            ToggleBgLayer(GF_BG_LYR_SUB_0, GF_PLANE_TOGGLE_OFF);
            ToggleBgLayer(GF_BG_LYR_SUB_2, GF_PLANE_TOGGLE_OFF);
            ToggleBgLayer(GF_BG_LYR_SUB_1, GF_PLANE_TOGGLE_OFF);
            data->state = OAK_SPEECH_MAIN_STATE_FADE_OUT_TUTORIAL_MENU_BGS;
        }
        break;
    case OAK_SPEECH_MAIN_STATE_FADE_OUT_TUTORIAL_MENU_BGS:
        BeginNormalPaletteFade(0, 0, 0, RGB_BLACK, 6, 1, data->heapId);
        data->state = OAK_SPEECH_MAIN_STATE_WAIT_FADE_OUT_TUTORIAL_MENU_BGS;
        break;
    case OAK_SPEECH_MAIN_STATE_WAIT_FADE_OUT_TUTORIAL_MENU_BGS:
        if (IsPaletteFadeFinished() == TRUE) {
            switch (data->menuData.cursorPos) {
            case 0: // CONTROL INFO
                data->state = OAK_SPEECH_MAIN_STATE_FADE_IN_CONTROL_INFO;
                break;
            case 1: // ADVENTURE INFO
                data->state = OAK_SPEECH_MAIN_STATE_FADE_IN_ADVENTURE_INFO;
                break;
            case 2: // NO INFO NEEDED
                data->state = OAK_SPEECH_MAIN_STATE_NO_INFO_NEEDED_FADE_IN;
                break;
            }
        }
        break;

    // CONTROL INFO
    case OAK_SPEECH_MAIN_STATE_FADE_IN_CONTROL_INFO:
        BgClearTilemapBufferAndCommit(data->bgConfig, GF_BG_LYR_SUB_0);
        OakSpeech_SetButtonTutorialScreenLayout(data, 1);
        ov53_021E67C4(data, 1);
        OakSpeech_TouchToAdvanceButtonAction(data, TOUCHTOADVANCE_SHOW);
        ToggleBgLayer(GF_BG_LYR_SUB_0, GF_PLANE_TOGGLE_ON);
        ToggleBgLayer(GF_BG_LYR_SUB_3, GF_PLANE_TOGGLE_ON);
        BeginNormalPaletteFade(0, 1, 1, RGB_BLACK, 6, 1, data->heapId);
        data->state = OAK_SPEECH_MAIN_STATE_WAIT_FADE_IN_CONTROL_INFO;
        break;
    case OAK_SPEECH_MAIN_STATE_WAIT_FADE_IN_CONTROL_INFO:
        if (IsPaletteFadeFinished() == TRUE) {
            data->state = OAK_SPEECH_MAIN_STATE_CONTROL_INFO_1;
        }
        break;
    case OAK_SPEECH_MAIN_STATE_CONTROL_INFO_1:
        if (OakSpeech_PrintAndFadeCenteredFullScreenText(data, 9, 0) == TRUE) {
            data->state = OAK_SPEECH_MAIN_STATE_CONTROL_INFO_2;
        }
        break;
    case OAK_SPEECH_MAIN_STATE_CONTROL_INFO_2:
        if (OakSpeech_PrintAndFadeCenteredFullScreenText(data, 10, 0) == TRUE) {
            data->state = OAK_SPEECH_MAIN_STATE_CONTROL_INFO_3;
        }
        break;
    case OAK_SPEECH_MAIN_STATE_CONTROL_INFO_3:
        if (OakSpeech_PrintAndFadeCenteredFullScreenText(data, 11, 0) == TRUE) {
            data->state = OAK_SPEECH_MAIN_STATE_CONTROL_INFO_4;
        }
        break;
    case OAK_SPEECH_MAIN_STATE_CONTROL_INFO_4:
        if (OakSpeech_PrintAndFadeCenteredFullScreenText(data, 12, 0) == TRUE) {
            data->state = OAK_SPEECH_MAIN_STATE_CONTROL_INFO_5;
        }
        break;
    case OAK_SPEECH_MAIN_STATE_CONTROL_INFO_5:
        if (OakSpeech_PrintAndFadeCenteredFullScreenText(data, 23, 2) == TRUE) {
            ToggleBgLayer(GF_BG_LYR_MAIN_0, GF_PLANE_TOGGLE_ON);
            data->state = OAK_SPEECH_MAIN_STATE_CONTROL_INFO_6;
        }
        break;
    case OAK_SPEECH_MAIN_STATE_CONTROL_INFO_6:
        if (OakSpeech_PrintDialogMsg(data, 25, 0) == TRUE) {
            data->state = OAK_SPEECH_MAIN_STATE_CONTROL_INFO_7;
        }
        break;
    case OAK_SPEECH_MAIN_STATE_CONTROL_INFO_7:
        if (OakSpeech_PrintAndFadeCenteredFullScreenText(data, 13, 0) == TRUE) {
            OakSpeech_SetButtonTutorialScreenLayout(data, 2);
            data->state = OAK_SPEECH_MAIN_STATE_CONTROL_INFO_8;
        }
        break;
    case OAK_SPEECH_MAIN_STATE_CONTROL_INFO_8:
        if (OakSpeech_PrintAndFadeCenteredFullScreenText(data, 14, 3) == TRUE) {
            OakSpeech_SetButtonTutorialScreenLayout(data, 1);
            data->state = OAK_SPEECH_MAIN_STATE_CONTROL_INFO_9;
        }
        break;
    case OAK_SPEECH_MAIN_STATE_CONTROL_INFO_9:
        if (OakSpeech_PrintAndFadeCenteredFullScreenText(data, 15, 0) == TRUE) {
            OakSpeech_SetButtonTutorialScreenLayout(data, 3);
            data->state = OAK_SPEECH_MAIN_STATE_CONTROL_INFO_10;
        }
        break;
    case OAK_SPEECH_MAIN_STATE_CONTROL_INFO_10:
        if (OakSpeech_PrintAndFadeCenteredFullScreenText(data, 16, 3) == TRUE) {
            OakSpeech_SetButtonTutorialScreenLayout(data, 4);
            data->state = OAK_SPEECH_MAIN_STATE_CONTROL_INFO_11;
        }
        break;
    case OAK_SPEECH_MAIN_STATE_CONTROL_INFO_11:
        if (OakSpeech_PrintAndFadeCenteredFullScreenText(data, 17, 3) == TRUE) {
            data->state = OAK_SPEECH_MAIN_STATE_CONTROL_INFO_23;
            ToggleBgLayer(GF_BG_LYR_MAIN_0, GF_PLANE_TOGGLE_ON);
            OakSpeech_SetButtonTutorialScreenLayout(data, 1);
        }
        break;
    case OAK_SPEECH_MAIN_STATE_CONTROL_INFO_23:
        if (OakSpeech_PrintDialogMsg(data, 26, 1) == TRUE) {
            data->state = OAK_SPEECH_MAIN_STATE_CONTROL_INFO_ASK_UNDERSTOOD;
        }
        break;
    case OAK_SPEECH_MAIN_STATE_CONTROL_INFO_ASK_UNDERSTOOD:
        OakSpeech_TouchToAdvanceButtonAction(data, TOUCHTOADVANCE_HIDE);
        BgClearTilemapBufferAndCommit(data->bgConfig, GF_BG_LYR_SUB_0);
        OakSpeechYesNo_SetBackgroundPalette(data->yesnoMenu, 7);
        // OakSpeechYesNo_Start(data->yesnoMenu, NARC_msg_msg_0219_bin, 61, 62);
        OakSpeechYesNo_Start(data->yesnoMenu, 219, 61, 62);
        data->state = OAK_SPEECH_MAIN_STATE_CONTROL_INFO_ASK_UNDERSTOOD_HANDLE_YESNO;
        break;
    case OAK_SPEECH_MAIN_STATE_CONTROL_INFO_ASK_UNDERSTOOD_HANDLE_YESNO:
        switch (OakSpeechYesNo_Main(data->yesnoMenu)) {
        case YESNORESPONSE_YES:
            data->state = OAK_SPEECH_MAIN_STATE_CONTROL_INFO_UNDERSTOOD_YES;
            break;
        case YESNORESPONSE_NO:
            data->state = OAK_SPEECH_MAIN_STATE_CONTROL_INFO_UNDERSTOOD_NO;
            break;
        }
        break;
    case OAK_SPEECH_MAIN_STATE_CONTROL_INFO_UNDERSTOOD_YES:
        if (OakSpeech_BlendLayer(data, GF_BG_LYR_SUB_2, TRUE) == TRUE) {
            BeginNormalPaletteFade(0, 0, 0, RGB_BLACK, 6, 1, data->heapId);
            data->state = OAK_SPEECH_MAIN_STATE_CONTROL_INFO_UNDERSTOOD_YES_WAIT_FADE;
        }
        break;
    case OAK_SPEECH_MAIN_STATE_CONTROL_INFO_UNDERSTOOD_YES_WAIT_FADE:
        if (IsPaletteFadeFinished() == TRUE) {
            OakSpeech_ClearBgLayer0TopBottomAndCommit(data);
            data->state = OAK_SPEECH_MAIN_STATE_FADE_IN_TUTORIAL_MENU;
        }
        break;
    case OAK_SPEECH_MAIN_STATE_CONTROL_INFO_UNDERSTOOD_NO:
        if (OakSpeech_BlendLayer(data, GF_BG_LYR_SUB_2, TRUE) == TRUE) {
            OakSpeech_TouchToAdvanceButtonAction(data, TOUCHTOADVANCE_RELEASE);
            ToggleBgLayer(GF_BG_LYR_SUB_2, GF_PLANE_TOGGLE_OFF);
            OakSpeech_ClearBgLayer0TopBottomAndCommit(data);
            data->state = OAK_SPEECH_MAIN_STATE_FADE_IN_CONTROL_INFO;
        }
        break;

    // ADVENTURE INFO
    case OAK_SPEECH_MAIN_STATE_FADE_IN_ADVENTURE_INFO:
        OakSpeech_SetButtonTutorialScreenLayout(data, 5);
        ov53_021E67C4(data, 2);
        OakSpeech_ClearBgLayer0TopBottomAndCommit(data);
        OakSpeech_TouchToAdvanceButtonAction(data, TOUCHTOADVANCE_SHOW);
        ToggleBgLayer(GF_BG_LYR_SUB_0, GF_PLANE_TOGGLE_ON);
        ToggleBgLayer(GF_BG_LYR_SUB_3, GF_PLANE_TOGGLE_ON);
        BeginNormalPaletteFade(0, 1, 1, RGB_BLACK, 6, 1, data->heapId);
        data->state = OAK_SPEECH_MAIN_STATE_WAIT_FADE_IN_ADVENTURE_INFO;
        break;
    case OAK_SPEECH_MAIN_STATE_WAIT_FADE_IN_ADVENTURE_INFO:
        if (IsPaletteFadeFinished() == TRUE) {
            data->state = OAK_SPEECH_MAIN_STATE_ADVENTURE_INFO_1;
        }
        break;
    case OAK_SPEECH_MAIN_STATE_ADVENTURE_INFO_1:
        if (OakSpeech_PrintAndFadeCenteredFullScreenText(data, 28, 1) == TRUE) {
            data->state = OAK_SPEECH_MAIN_STATE_ADVENTURE_INFO_2;
        }
        break;
    case OAK_SPEECH_MAIN_STATE_ADVENTURE_INFO_2:
        if (OakSpeech_PrintAndFadeCenteredFullScreenText(data, 29, 1) == TRUE) {
            data->state = OAK_SPEECH_MAIN_STATE_ADVENTURE_INFO_3;
        }
        break;
    case OAK_SPEECH_MAIN_STATE_ADVENTURE_INFO_3:
        if (OakSpeech_PrintAndFadeCenteredFullScreenText(data, 30, 1) == TRUE) {
            data->state = OAK_SPEECH_MAIN_STATE_ADVENTURE_INFO_4;
        }
        break;
    case OAK_SPEECH_MAIN_STATE_ADVENTURE_INFO_4:
        if (OakSpeech_PrintAndFadeCenteredFullScreenText(data, 31, 1) == TRUE) {
            data->state = OAK_SPEECH_MAIN_STATE_ADVENTURE_INFO_5;
        }
        break;
    case OAK_SPEECH_MAIN_STATE_ADVENTURE_INFO_5:
        if (OakSpeech_PrintAndFadeCenteredFullScreenText(data, 32, 1) == TRUE) {
            data->state = OAK_SPEECH_MAIN_STATE_ADVENTURE_INFO_6;
        }
        break;
    case OAK_SPEECH_MAIN_STATE_ADVENTURE_INFO_6:
        if (OakSpeech_PrintAndFadeCenteredFullScreenText(data, 33, 1) == TRUE) {
            data->state = OAK_SPEECH_MAIN_STATE_ADVENTURE_INFO_FADE_OUT;
        }
        break;
    case OAK_SPEECH_MAIN_STATE_ADVENTURE_INFO_FADE_OUT:
        BeginNormalPaletteFade(0, 0, 0, RGB_BLACK, 6, 1, data->heapId);
        data->state = OAK_SPEECH_MAIN_STATE_WAIT_FADE_OUT_ADVENTURE_INFO;
        break;
    case OAK_SPEECH_MAIN_STATE_WAIT_FADE_OUT_ADVENTURE_INFO:
        if (IsPaletteFadeFinished() == TRUE) {
            OakSpeech_ClearBgLayer0TopBottomAndCommit(data);
            OakSpeech_TouchToAdvanceButtonAction(data, TOUCHTOADVANCE_HIDE);
            ToggleBgLayer(GF_BG_LYR_MAIN_0, GF_PLANE_TOGGLE_ON);
            data->state = OAK_SPEECH_MAIN_STATE_FADE_IN_TUTORIAL_MENU;
        }
        break;

    // NO INFO NEEDED
    case OAK_SPEECH_MAIN_STATE_NO_INFO_NEEDED_FADE_IN:
        OakSpeech_ClearBgLayer0TopBottomAndCommit(data);
        OakSpeech_TouchToAdvanceButtonAction(data, TOUCHTOADVANCE_SHOW);
        OakSpeech_SetButtonTutorialScreenLayout(data, 0);
        BgClearTilemapBufferAndCommit(data->bgConfig, GF_BG_LYR_SUB_1);
        ToggleBgLayer(GF_BG_LYR_MAIN_0, GF_PLANE_TOGGLE_ON);
        ToggleBgLayer(GF_BG_LYR_MAIN_3, GF_PLANE_TOGGLE_OFF);
        ToggleBgLayer(GF_BG_LYR_SUB_0, GF_PLANE_TOGGLE_ON);
        ToggleBgLayer(GF_BG_LYR_SUB_3, GF_PLANE_TOGGLE_ON);
        data->state = OAK_SPEECH_MAIN_STATE_WAIT_FADE_IN_NO_INFO_NEEDED;
        BeginNormalPaletteFade(0, 1, 1, RGB_BLACK, 6, 1, data->heapId);
        break;
    case OAK_SPEECH_MAIN_STATE_WAIT_FADE_IN_NO_INFO_NEEDED:
        if (IsPaletteFadeFinished() == TRUE && OakSpeech_WaitFrames(data, 40) == TRUE) {
            data->state = OAK_SPEECH_MAIN_STATE_PRINT_TIME_OF_DAY_MSG;
            data->queuedMsgId = OakSpeech_GetTimeOfDayIntroMsg();
        }
        break;
    case OAK_SPEECH_MAIN_STATE_PRINT_TIME_OF_DAY_MSG:
        if (OakSpeech_PrintDialogMsg(data, data->queuedMsgId, 1) == TRUE) {
            GF_SndStartFadeOutBGM(0, 6);
            data->state = OAK_SPEECH_MAIN_STATE_SHOW_OAK;
        }
        break;
    case OAK_SPEECH_MAIN_STATE_SHOW_OAK:
        if (GF_SndGetFadeTimer() == 0) {
            StopBGM(SEQ_GS_STARTING, 0);
            PlayBGM(SEQ_GS_STARTING2);
            OakSpeech_DrawPicOnBgLayer(data, OAK_SPEECH_PIC_OAK, OAK_SPEECH_PIC_NONE);
            ToggleBgLayer(GF_BG_LYR_MAIN_3, GF_PLANE_TOGGLE_ON);
            ToggleBgLayer(GF_BG_LYR_MAIN_1, GF_PLANE_TOGGLE_ON);
            StartBrightnessTransition(16, 0, -16, (GXBlendPlaneMask)(GX_BLEND_PLANEMASK_BG1 | GX_BLEND_PLANEMASK_BG3 | GX_BLEND_PLANEMASK_OBJ), SCREEN_MASK_MAIN);
            data->state = OAK_SPEECH_MAIN_STATE_WAIT_FADE_IN_OAK;
        }
        break;
    case OAK_SPEECH_MAIN_STATE_WAIT_FADE_IN_OAK:
        if (IsBrightnessTransitionActive(SCREEN_MASK_MAIN)) {
            data->state = OAK_SPEECH_MAIN_STATE_WELCOME_TO_WORLD;
        }
        break;
    case OAK_SPEECH_MAIN_STATE_WELCOME_TO_WORLD:
        if (OakSpeech_PrintDialogMsg(data, 06, 1) == TRUE) {
            data->state = OAK_SPEECH_MAIN_STATE_SLIDE_OAK_RIGHT;
        }
        break;
    case OAK_SPEECH_MAIN_STATE_SLIDE_OAK_RIGHT:
        if (OakSpeech_TranslateOakPicHorizontally(data, GF_BG_LYR_MAIN_1, 0) == TRUE) {
            data->state = OAK_SPEECH_MAIN_STATE_THIS_WORLD_IS_INHABITED;
        }
        break;
    case OAK_SPEECH_MAIN_STATE_THIS_WORLD_IS_INHABITED:
        if (OakSpeech_PrintDialogMsg(data, 34, 1) == TRUE) {
            Sprite_SetAnimCtrlSeq(data->sprites[5], 3);
            Sprite_SetPalIndex(data->sprites[5], 5);
            Sprite_SetVisibleFlag(data->sprites[5], TRUE);
            data->state = OAK_SPEECH_MAIN_STATE_BALL_OPENING_FLASH;
        }
        break;
    case OAK_SPEECH_MAIN_STATE_BALL_OPENING_FLASH:
        if (OakSpeech_WaitFrames(data, 30) == TRUE) {
            StartBrightnessTransition(4, 0, 16, (GXBlendPlaneMask)(GX_BLEND_PLANEMASK_BG0 | GX_BLEND_PLANEMASK_BG1 | GX_BLEND_PLANEMASK_BG3 | GX_BLEND_PLANEMASK_OBJ), SCREEN_MASK_MAIN);
            StartBrightnessTransition(4, 0, 16, (GXBlendPlaneMask)(GX_BLEND_PLANEMASK_BG0 | GX_BLEND_PLANEMASK_BG2 | GX_BLEND_PLANEMASK_BG3 | GX_BLEND_PLANEMASK_OBJ), SCREEN_MASK_SUB);
            PlaySE(SEQ_SE_DP_BOWA2);
            data->playerPicShrinkAnimStep = 0;
            data->state = OAK_SPEECH_MAIN_STATE_APPEAR_MARILL;
        }
        break;
    case OAK_SPEECH_MAIN_STATE_APPEAR_MARILL:
        if (IsBrightnessTransitionActive(SCREEN_MASK_MAIN) == TRUE && IsBrightnessTransitionActive(SCREEN_MASK_SUB) == TRUE) {
            Sprite_SetAnimCtrlSeq(data->sprites[5], 1);
            Sprite_SetPalIndex(data->sprites[5], 4);
            data->playerPicShrinkAnimStep = 16;
            G2_SetBlendBrightness(GX_BLEND_PLANEMASK_OBJ, data->playerPicShrinkAnimStep);
            data->state = OAK_SPEECH_MAIN_STATE_MARILL_CRY;
        }
        break;
    case OAK_SPEECH_MAIN_STATE_MARILL_CRY:
        if (!Sprite_IsCellAnimationRunning(data->sprites[5])) {
            --data->playerPicShrinkAnimStep;
            G2_SetBlendBrightness(GX_BLEND_PLANEMASK_OBJ, data->playerPicShrinkAnimStep);
            if (data->playerPicShrinkAnimStep == 0) {
                Sprite_SetAnimCtrlSeq(data->sprites[5], 2);
                PlayCry(SPECIES_MARILL, 0);
                data->state = OAK_SPEECH_MAIN_STATE_WAIT_MARILL_CRY;
            }
        }
        break;
    case OAK_SPEECH_MAIN_STATE_WAIT_MARILL_CRY:
        if (OakSpeech_WaitFrames(data, 40) == TRUE) {
            data->state = OAK_SPEECH_MAIN_STATE_WE_LIVE_ALONGSIDE;
        }
        break;
    case OAK_SPEECH_MAIN_STATE_WE_LIVE_ALONGSIDE:
        if (OakSpeech_PrintDialogMsg(data, 35, 1) == TRUE) {
            data->state = OAK_SPEECH_MAIN_STATE_HIDE_MARILL;
        }
        break;
    case OAK_SPEECH_MAIN_STATE_HIDE_MARILL:
        if (OakSpeech_BlendLayer(data, 101, TRUE) == TRUE) {
            data->state = OAK_SPEECH_MAIN_STATE_WAIT_AFTER_HIDE_MARILL;
        }
        break;
    case OAK_SPEECH_MAIN_STATE_WAIT_AFTER_HIDE_MARILL:
        if (OakSpeech_WaitFrames(data, 30) == TRUE) {
            data->state = OAK_SPEECH_MAIN_STATE_SLIDE_OAK_LEFT;
        }
        break;
    case OAK_SPEECH_MAIN_STATE_SLIDE_OAK_LEFT:
        if (OakSpeech_TranslateOakPicHorizontally(data, GF_BG_LYR_MAIN_1, 1) == TRUE) {
            data->state = OAK_SPEECH_MAIN_STATE_TELL_ME_ABOUT_YOURSELF;
        }
        break;
    case OAK_SPEECH_MAIN_STATE_TELL_ME_ABOUT_YOURSELF:
        if (OakSpeech_PrintDialogMsg(data, 36, 1) == TRUE) {
            data->state = OAK_SPEECH_MAIN_STATE_ARE_YOU_A_GENDER;
            data->menuData.cursorPos = 0;
            data->menuData.numOptions = 2;
        }
        break;
    case OAK_SPEECH_MAIN_STATE_ARE_YOU_A_GENDER:
        if (OakSpeech_PrintDialogMsg(data, 37, 1) == TRUE) {
            data->state = OAK_SPEECH_MAIN_STATE_WAIT_FADE_OUT_TO_ASK_GENDER;
            BeginNormalPaletteFade(4, 0, 0, RGB_BLACK, 6, 1, data->heapId);
        }
        break;
    case OAK_SPEECH_MAIN_STATE_WAIT_FADE_OUT_TO_ASK_GENDER:
        if (IsPaletteFadeFinished() == TRUE) {
            data->state = OAK_SPEECH_MAIN_STATE_SETUP_GENDER_SELECT_MENU;
        }
        break;
    case OAK_SPEECH_MAIN_STATE_SETUP_GENDER_SELECT_MENU:
        OakSpeech_TouchToAdvanceButtonAction(data, TOUCHTOADVANCE_HIDE);
        ToggleBgLayer(GF_BG_LYR_SUB_0, GF_PLANE_TOGGLE_OFF);
        ov53_021E67C4(data, 4);
        OakSpeech_SelectedGenderIndicatorSpritesAction(data, GENDER_CURSOR_BOTH);
        BgClearTilemapBufferAndCommit(data->bgConfig, GF_BG_LYR_SUB_2);
        BeginNormalPaletteFade(4, 1, 1, RGB_BLACK, 6, 1, data->heapId);
        data->state = OAK_SPEECH_MAIN_STATE_WAIT_FADE_IN_GENDER_SELECT_MENU;
        break;
    case OAK_SPEECH_MAIN_STATE_WAIT_FADE_IN_GENDER_SELECT_MENU:
        if (IsPaletteFadeFinished() == TRUE) {
            data->menuData.cursorPos = data->lastChosenGender;
            data->state = OAK_SPEECH_MAIN_STATE_GENDER_SELECT_MENU_HANDLE_INPUT;
        }
        break;
    case OAK_SPEECH_MAIN_STATE_GENDER_SELECT_MENU_HANDLE_INPUT:
        if (OakSpeech_GenderSelectHandleInput(data)) {
            data->state = OAK_SPEECH_MAIN_STATE_PREPARE_ASK_CONFIRM_GENDER;
            data->playerGender = data->menuData.cursorPos;
        }
        break;
    case OAK_SPEECH_MAIN_STATE_PREPARE_ASK_CONFIRM_GENDER:
        FillBgTilemapRect(data->bgConfig, GF_BG_LYR_SUB_3, 1, 16 * (data->menuData.cursorPos ^ 1), 0, 16, 23, 0);
        BgCommitTilemapBufferToVram(data->bgConfig, GF_BG_LYR_SUB_2);
        BgCommitTilemapBufferToVram(data->bgConfig, GF_BG_LYR_SUB_3);
        BgClearTilemapBufferAndCommit(data->bgConfig, GF_BG_LYR_SUB_0);
        OakSpeech_SelectedGenderIndicatorSpritesAction(data, data->playerGender);
        if (data->playerGender == PLAYER_GENDER_MALE) {
            data->queuedMsgId = 38;
        } else {
            data->queuedMsgId = 39;
        }
        data->state = OAK_SPEECH_MAIN_STATE_ASK_CONFIRM_GENDER;
        break;
    case OAK_SPEECH_MAIN_STATE_ASK_CONFIRM_GENDER:
        if (OakSpeech_PrintDialogMsg(data, data->queuedMsgId, 1) == TRUE) {
            data->state = OAK_SPEECH_MAIN_STATE_CONFIRM_GENDER_YESNO_INIT_MENU;
        }
        break;
    case OAK_SPEECH_MAIN_STATE_CONFIRM_GENDER_YESNO_INIT_MENU:
        OakSpeech_InitMultichoiceMenu(&data->menuData, 1);
        ov53_021E6824(data, 1);
        OakSpeech_PrintMultichoiceMenu(data, 47, 48, 0, 2);
        data->state = OAK_SPEECH_MAIN_STATE_CONFIRM_GENDER_YESNO_HANDLE_INPUT;
        data->menuData.cursorPos = 0;
        break;

    case OAK_SPEECH_MAIN_STATE_CONFIRM_GENDER_YESNO_HANDLE_INPUT:
        ToggleBgLayer(GF_BG_LYR_SUB_0, GF_PLANE_TOGGLE_ON);
        ToggleBgLayer(GF_BG_LYR_SUB_2, GF_PLANE_TOGGLE_ON);
        if (OakSpeech_MultichoiceMenuHandleInputVertical(data, data->playerGender + 1) != -1) {
            OakSpeech_FreeWindows(data);
            data->state = OAK_SPEECH_MAIN_STATE_CONFIRM_GENDER_YESNO_HANDLE_RESULT;
        }
        break;
    case OAK_SPEECH_MAIN_STATE_CONFIRM_GENDER_YESNO_HANDLE_RESULT:
        switch (data->menuData.cursorPos) {
        case 0: // Yes
            data->state = OAK_SPEECH_MAIN_STATE_CONFIRM_GENDER_YES;
            break;
        case 1: // No
            data->state = OAK_SPEECH_MAIN_STATE_CONFIRM_GENDER_NO_WAIT_FADE_OUT;
            BeginNormalPaletteFade(4, 0, 0, RGB_BLACK, 6, 1, data->heapId);
            break;
        }
        break;

    case OAK_SPEECH_MAIN_STATE_CONFIRM_GENDER_NO_WAIT_FADE_OUT:
        if (IsPaletteFadeFinished() == TRUE) {

            ToggleBgLayer(GF_BG_LYR_SUB_1, GF_PLANE_TOGGLE_OFF);
            ToggleBgLayer(GF_BG_LYR_SUB_2, GF_PLANE_TOGGLE_OFF);
            OakSpeech_SelectedGenderIndicatorSpritesAction(data, GENDER_CURSOR_NEITHER);
            ov53_021E67C4(data, 1);
            BgClearTilemapBufferAndCommit(data->bgConfig, GF_BG_LYR_SUB_0);
            ScheduleSetBgPosText(data->bgConfig, GF_BG_LYR_SUB_0, BG_POS_OP_SET_X, 0);
            OakSpeech_StopHighlightedGenderFrameBlink(data);
            BeginNormalPaletteFade(4, 1, 1, RGB_BLACK, 6, 1, data->heapId);
            data->state = OAK_SPEECH_MAIN_STATE_CONFIRM_GENDER_NO_WAIT_FADE_IN;
        }
        break;
    case OAK_SPEECH_MAIN_STATE_CONFIRM_GENDER_NO_WAIT_FADE_IN:
        if (IsPaletteFadeFinished() == TRUE) {
            OakSpeech_TouchToAdvanceButtonAction(data, TOUCHTOADVANCE_SHOW);
            data->state = OAK_SPEECH_MAIN_STATE_ARE_YOU_A_GENDER;
        }
        break;

        // 73-92 don't exist

    case OAK_SPEECH_MAIN_STATE_CONFIRM_GENDER_YES:
        if (OakSpeech_PrintDialogMsg(data, 40, 1) == TRUE) {
            data->state = OAK_SPEECH_MAIN_STATE_PROMPT_NAME_DELAY_BEFORE;
        }
        break;

    case OAK_SPEECH_MAIN_STATE_PROMPT_NAME_DELAY_BEFORE:
        if (OakSpeech_WaitFrames(data, 40)) {
            data->state = OAK_SPEECH_MAIN_STATE_PROMPT_NAME_LAUNCH_NAMING_SCREEN;
        }
        break;

    case OAK_SPEECH_MAIN_STATE_PROMPT_NAME_LAUNCH_NAMING_SCREEN:
        String_SetEmpty(data->namingScreenArgs_Player->nameInputString);
        data->namingScreenArgs_Player->playerGenderOrMonSpecies = data->playerGender;
        // TODO
        // data->overlayManager = OverlayManager_New(&gOverlayTemplate_NamingScreen, data->namingScreenArgs_Player, data->heapId);
        data->state = OAK_SPEECH_MAIN_STATE_PROMPT_NAME_RESTORE_GRAPHICS_AFTER;
        break;

    case OAK_SPEECH_MAIN_STATE_PROMPT_NAME_RESTORE_GRAPHICS_AFTER:
        ToggleBgLayer(GF_BG_LYR_MAIN_0, GF_PLANE_TOGGLE_ON);
        ToggleBgLayer(GF_BG_LYR_MAIN_1, GF_PLANE_TOGGLE_ON);
        ToggleBgLayer(GF_BG_LYR_MAIN_3, GF_PLANE_TOGGLE_ON);
        ToggleBgLayer(GF_BG_LYR_SUB_0, GF_PLANE_TOGGLE_ON);
        ToggleBgLayer(GF_BG_LYR_SUB_3, GF_PLANE_TOGGLE_ON);
        ToggleBgLayer(GF_BG_LYR_SUB_2, GF_PLANE_TOGGLE_ON);
        BgSetPosTextAndCommit(data->bgConfig, GF_BG_LYR_MAIN_1, BG_POS_OP_SET_X, 0);
        OakSpeech_CreateMultichoiceYesNoMenu(data);
        BeginNormalPaletteFade(0, 1, 1, RGB_BLACK, 6, 1, data->heapId);
        data->state = OAK_SPEECH_MAIN_STATE_CONFIRM_NAME_YESNO_INIT_MENU;
        OakSpeech_DrawPicOnBgLayer(data, OAK_SPEECH_PIC_OAK, OAK_SPEECH_PIC_NONE);
        OakSpeech_SelectedGenderIndicatorSpritesAction(data, data->playerGender);
        // Vestige of gendered grammar in Japanese
        // Both messages are the same in English
        if (data->playerGender == 0) {
            data->queuedMsgId = 41;
        } else {
            data->queuedMsgId = 42;
        }
        break;

    case OAK_SPEECH_MAIN_STATE_CONFIRM_NAME_YESNO_INIT_MENU:
        if (OakSpeech_PrintDialogMsg(data, data->queuedMsgId, 1) == TRUE) {
            data->state = OAK_SPEECH_MAIN_STATE_CONFIRM_NAME_YESNO_HANDLE_INPUT;
            OakSpeech_InitMultichoiceMenu(&data->menuData, 1);
        }
        break;

    case OAK_SPEECH_MAIN_STATE_CONFIRM_NAME_YESNO_HANDLE_INPUT:
        if (OakSpeech_MultichoiceMenuHandleInputVertical(data, data->playerGender + 1) != -1) {
            OakSpeech_FreeWindows(data);
            data->state = OAK_SPEECH_MAIN_STATE_CONFIRM_NAME_YESNO_HANDLE_RESULT;
        }
        break;

    case OAK_SPEECH_MAIN_STATE_CONFIRM_NAME_YESNO_HANDLE_RESULT:
        switch (data->menuData.cursorPos) {
        case 0: // Yes
            data->state = OAK_SPEECH_MAIN_STATE_CONFIRM_NAME_YES;
            break;
        case 1: // No
            BeginNormalPaletteFade(4, 0, 0, RGB_BLACK, 6, 1, data->heapId);
            data->state = OAK_SPEECH_MAIN_STATE_CONFIRM_GENDER_NO_WAIT_FADE_OUT;
            break;
        }
        break;

    case OAK_SPEECH_MAIN_STATE_CONFIRM_NAME_YES:
        BeginNormalPaletteFade(4, 0, 0, RGB_BLACK, 6, 1, data->heapId);
        data->state = OAK_SPEECH_MAIN_STATE_CONFIRM_NAME_YES_WAIT_FADE_OUT;
        break;

    case OAK_SPEECH_MAIN_STATE_CONFIRM_NAME_YES_WAIT_FADE_OUT:
        if (IsPaletteFadeFinished() == TRUE) {
            ToggleBgLayer(GF_BG_LYR_SUB_2, GF_PLANE_TOGGLE_OFF);
            ToggleBgLayer(GF_BG_LYR_SUB_1, GF_PLANE_TOGGLE_OFF);
            ov53_021E67C4(data, 1);
            OakSpeech_SelectedGenderIndicatorSpritesAction(data, GENDER_CURSOR_NEITHER);
            BgClearTilemapBufferAndCommit(data->bgConfig, GF_BG_LYR_SUB_0);
            ScheduleSetBgPosText(data->bgConfig, GF_BG_LYR_SUB_0, BG_POS_OP_SET_X, 0);
            OakSpeech_TouchToAdvanceButtonAction(data, TOUCHTOADVANCE_SHOW);
            BeginNormalPaletteFade(4, 1, 1, RGB_BLACK, 6, 1, data->heapId);
            data->state = OAK_SPEECH_MAIN_STATE_CONFIRM_NAME_YES_WAIT_FADE_IN;
        }
        break;

    case OAK_SPEECH_MAIN_STATE_CONFIRM_NAME_YES_WAIT_FADE_IN:
        if (IsPaletteFadeFinished() == TRUE) {
            data->state = OAK_SPEECH_MAIN_STATE_YOUR_ADVENTURE_UNFOLDS;
        }
        break;

    case OAK_SPEECH_MAIN_STATE_YOUR_ADVENTURE_UNFOLDS:
        if (OakSpeech_PrintDialogMsg(data, 43, 1) == TRUE) {
            data->state = OAK_SPEECH_MAIN_STATE_FADE_OUT_FROM_LAST_OAK_MESSAGE;
        }
        break;

        // 104-109 don't exist

    case OAK_SPEECH_MAIN_STATE_FADE_OUT_FROM_LAST_OAK_MESSAGE:
        BeginNormalPaletteFade(0, 0, 0, RGB_BLACK, 6, 1, data->heapId);
        data->state = OAK_SPEECH_MAIN_STATE_WAIT_FADE_OUT_FROM_LAST_OAK_MESSAGE;
        break;

    case OAK_SPEECH_MAIN_STATE_WAIT_FADE_OUT_FROM_LAST_OAK_MESSAGE:
        if (IsPaletteFadeFinished() == TRUE) {
            data->state = OAK_SPEECH_MAIN_STATE_FADE_IN_TO_SHRINK_ANIM;
        }
        break;

        // 112-119 don't exist

    case OAK_SPEECH_MAIN_STATE_FADE_IN_TO_SHRINK_ANIM:
        if (data->playerGender == PLAYER_GENDER_MALE) {
            OakSpeech_DrawPicOnBgLayer(data, OAK_SPEECH_PIC_ETHAN, OAK_SPEECH_PIC_NONE);
        } else {
            OakSpeech_DrawPicOnBgLayer(data, OAK_SPEECH_PIC_LYRA, OAK_SPEECH_PIC_NONE);
        }
        BeginNormalPaletteFade(0, 1, 1, RGB_BLACK, 6, 1, data->heapId);
        data->state = OAK_SPEECH_MAIN_STATE_WAIT_FADE_IN_TO_SHRINK_ANIM;
        ToggleBgLayer(GF_BG_LYR_MAIN_0, GF_PLANE_TOGGLE_OFF);
        break;

    case OAK_SPEECH_MAIN_STATE_WAIT_FADE_IN_TO_SHRINK_ANIM:
        if (IsPaletteFadeFinished() == TRUE) {
            data->state = OAK_SPEECH_MAIN_STATE_NOP_BEFORE_SHRINK_ANIM;
        }
        // Fallthrough into case 123

        // 122 doesn't exist

    case OAK_SPEECH_MAIN_STATE_NOP_BEFORE_SHRINK_ANIM:
        data->state = OAK_SPEECH_MAIN_STATE_INIT_SHRINK_ANIM_STATE;
        break;

    case OAK_SPEECH_MAIN_STATE_INIT_SHRINK_ANIM_STATE:
        OakSpeech_TouchToAdvanceButtonAction(data, TOUCHTOADVANCE_HIDE);
        OakSpeech_InitPlayerPicShrinkAnim(data);
        data->state = OAK_SPEECH_MAIN_STATE_DELAY_BEFORE_SHRINK_ANIM;
        break;

    case OAK_SPEECH_MAIN_STATE_DELAY_BEFORE_SHRINK_ANIM:
        if (OakSpeech_WaitFrames(data, 30) == TRUE) {
            PlaySE(SEQ_SE_GS_HERO_SHUKUSHOU);
            data->state = OAK_SPEECH_MAIN_STATE_RUN_SHRINK_ANIM;
        }
        break;

    case OAK_SPEECH_MAIN_STATE_RUN_SHRINK_ANIM:
        if (OakSpeech_PlayerPicShrinkAnim(data) == TRUE) {
            ret = TRUE;
        }
        break;
    }

    return ret;
    */
}