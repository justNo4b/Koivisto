//
// Created by Luecx on 06.12.2020.
//

#include "psqt.h"

EvalScore piece_square_tables[64][64][12][64]{};

// indexed by piece
EvalScore piece_values[6] = {
    M(90, 104), M(463, 326), M(474, 288), M(577, 594), M(1359, 1121), M(0, 0),
};


// indexed by piece, relation to king
EvalScore piece_our_king_square_table[5][15*15]{
    {
        M(    0,    0), M(    0,    0), M(    0,    0), M(    0,    0), M(    0,    0),
        M(    0,    0), M(    0,    0), M(    0,    0), M(    0,    0), M(    0,    0),
        M(    0,    0), M(    0,    0), M(    0,    0), M(    0,    0), M(    0,    0),
        M(   28,   42), M(   12,  -95), M(  -82,   11), M( -125,   30), M( -117,    0),
        M(  -84,  -19), M(  -29,  -43), M(  -18,  -68), M(  -31,  -38), M(  -83,   -7),
        M(  -66,    2), M(  -81,   24), M(  -31,   25), M(  -12,   20), M(  -36,   43),
        M(  -71,  -31), M(  -40,   -2), M(  -31,  -16), M(  -66,   -9), M(  -46,   -4),
        M(  -59,   -3), M(  -22,  -23), M(  -53,   -6), M(  -42,  -23), M(  -35,  -15),
        M(  -28,  -19), M(  -22,    4), M(  -22,    4), M(    2,    4), M(   11,   -4),
        M(  -32,  -37), M(  -26,  -10), M(  -14,   -4), M(  -20,   -9), M(  -44,    2),
        M(  -26,  -16), M(  -23,  -11), M(  -10,  -15), M(  -14,  -25), M(  -25,  -16),
        M(  -12,  -15), M(  -16,    2), M(  -11,   -1), M(   -8,   -4), M(   -9,  -10),
        M(  -44,   -4), M(    0,   -8), M(  -10,   10), M(   -5,    0), M(  -13,    4),
        M(   -7,   -4), M(    6,    0), M(   18,  -11), M(   -1,  -12), M(  -11,   -4),
        M(  -15,   -0), M(  -12,    0), M(   -7,   -2), M(   -4,   -6), M(    6,  -21),
        M(  -21,   -4), M(    2,   -4), M(  -10,    1), M(   -4,    3), M(   -6,    6),
        M(    1,    8), M(   24,    4), M(   35,    0), M(   10,    6), M(    6,    7),
        M(   -7,    1), M(   -7,    0), M(  -11,    3), M(   -6,   -2), M(    4,  -20),
        M(  -59,   14), M(   -7,   -6), M(  -13,    6), M(   -8,    0), M(    1,    7),
        M(    1,   12), M(   -6,  -17), M(   11,  -11), M(   -5,  -10), M(    1,    9),
        M(   -4,    8), M(  -10,    2), M(  -12,    3), M(   -5,   -1), M(    4,  -16),
        M(  -50,    3), M(    5,   -3), M(  -17,    6), M(   -0,    2), M(   13,    7),
        M(   -0,   16), M(    0,   -7), M(    0,    0), M(   10,   -7), M(    3,   14),
        M(   -2,    7), M(  -14,    7), M(   -8,    2), M(   -6,    1), M(    9,  -13),
        M(   -4,   14), M(   31,   -5), M(    7,   -1), M(    1,   -0), M(    0,   10),
        M(  -15,   17), M(  -48,    6), M(  -40,   27), M(  -56,    0), M(  -12,   19),
        M(  -21,   11), M(  -18,    8), M(  -13,    5), M(   -4,    2), M(  -10,    6),
        M(    3,    3), M(   34,  -16), M(  -43,    8), M(  -40,    1), M(  -45,   14),
        M(  -99,   25), M(  -64,   28), M(  -49,   18), M(  -75,   20), M(  -66,    7),
        M(  -60,   23), M(  -36,   11), M(  -33,   10), M(  -43,   16), M(  -50,   25),
        M(   43,  -21), M( -187,   32), M(  -24,   16), M(  -89,   11), M(  -85,   15),
        M( -121,   27), M(  -91,   25), M( -111,   39), M( -127,   24), M( -125,   17),
        M( -151,   39), M(  -47,    4), M( -146,   20), M(  -26,   13), M( -129,   22),
        M( -240,    7), M( -175,   -3), M(  178,  -14), M( -187,   27), M( -129,   29),
        M( -139,   30), M( -108,   33), M( -111,   45), M( -110,   22), M( -124,   30),
        M( -144,   28), M( -241,   31), M(  -35,   12), M(   64,   -5), M( -457,   57),
        M( -603,  123), M( -290,    6), M( -176,   41), M( -263,   76), M( -246,   33),
        M(  -98,   29), M(  -15,   45), M( -121,   43), M(  -59,   28), M( -156,   58),
        M(  246,  -41), M(  -26,    5), M( -247,   22), M(  -93,  107), M( -646,   35),
        M( -254,   96), M(-1906,  156), M(  571,   46), M( -785,  138), M(  506,   15),
        M( -415,  247), M( -423,   86), M( -305,  162), M( -758,  125), M( -705,   18),
        M(  441, -124), M( -139,   52), M(  920,  -75), M(   22,  -68), M(  281,  -92),
        M(    0,    0), M(    0,    0), M(    0,    0), M(    0,    0), M(    0,    0),
        M(    0,    0), M(    0,    0), M(    0,    0), M(    0,    0), M(    0,    0),
        M(    0,    0), M(    0,    0), M(    0,    0), M(    0,    0), M(    0,    0),
    },
    {
    
    },
    {
    
    },
    {
    
    },
    {
    
    },
};
EvalScore piece_opp_king_square_table[5][15*15]{
    {
        M(    0,    0), M(    0,    0), M(    0,    0), M(    0,    0), M(    0,    0),
        M(    0,    0), M(    0,    0), M(    0,    0), M(    0,    0), M(    0,    0),
        M(    0,    0), M(    0,    0), M(    0,    0), M(    0,    0), M(    0,    0),
        M(   -5,   46), M( -491,  195), M( -323,  150), M( -285,  147), M( -246,  201),
        M( -246,  202), M(   37,  201), M( -190,  310), M(   24,  228), M(  -57,  201),
        M(   15,  154), M( -721,  233), M( -603,  157), M( -317,  104), M( -394,   99),
        M( -208,  136), M( -433,  120), M( -318,  101), M( -353,  122), M( -257,  137),
        M( -275,  194), M( -233,  191), M( -209,  168), M( -128,  156), M( -180,  162),
        M(  -71,  103), M( -324,   99), M( -440,  101), M( -606,  151), M( -244,   62),
        M( -290,  108), M( -239,   74), M( -251,   61), M( -196,   45), M( -111,   65),
        M(  -96,   98), M( -141,  121), M(  -91,  103), M( -105,   97), M( -106,   94),
        M(  -89,   58), M( -130,   20), M( -208,   34), M( -299,   67), M( -317,   44),
        M( -216,   39), M( -143,   31), M(  -93,   17), M( -120,   20), M(  -60,   29),
        M(  -81,   51), M(  -98,   61), M(  -81,   48), M(  -12,   44), M(  -93,   47),
        M(  -74,   23), M(  -94,    4), M( -101,   18), M( -165,   28), M( -234,   54),
        M( -102,   28), M(  -68,   15), M(  -69,   12), M(  -58,    1), M(  -27,   14),
        M(  -57,   13), M(  -93,   24), M(  -86,   14), M(  -86,   20), M(  -63,   10),
        M(  -63,   24), M(  -70,    0), M(  -70,   10), M(  -69,   21), M(  -77,   30),
        M(  -44,   18), M(   -5,    5), M(  -16,   -0), M(   -5,   -6), M(   26,   -3),
        M(  -40,    8), M(  -69,   -3), M(  -94,   -3), M( -104,   -0), M(  -55,    9),
        M(  -20,    6), M(  -22,    1), M(  -19,    6), M(  -42,   23), M(  -43,   26),
        M(   12,   17), M(    6,    2), M(   24,   -4), M(   12,   -8), M(   20,   -3),
        M(    9,    0), M(   20,  -50), M(    0,    0), M(   -7,  -52), M(  -22,    7),
        M(   -4,    3), M(   -5,    4), M(   -4,    9), M(  -15,   17), M(  -23,   29),
        M(   -8,   17), M(   15,    5), M(   13,    3), M(   19,   -3), M(   29,   -1),
        M(   29,    2), M(  -77,  -21), M(  -79,  -25), M(  -76,  -23), M(   13,    5),
        M(    5,    9), M(    1,    9), M(   -5,   16), M(  -12,   23), M(  -19,   29),
        M(    0,   15), M(    2,   14), M(    8,    7), M(   14,    5), M(   26,    0),
        M(   26,    7), M(   40,    2), M(   45,   -3), M(   46,    4), M(   17,   10),
        M(    6,    9), M(   -1,   16), M(   -5,   18), M(   -5,   24), M(   -9,   22),
        M(  -11,   22), M(    8,   13), M(   -1,   15), M(   12,    9), M(   24,    3),
        M(   23,    5), M(   21,    7), M(    6,    5), M(   24,    8), M(   17,    9),
        M(    5,   11), M(    5,   16), M(    1,   21), M(    1,   21), M(   -6,   23),
        M(  -10,   17), M(    4,   17), M(    3,   17), M(    1,   16), M(   10,   10),
        M(   11,    5), M(    7,    7), M(    2,    1), M(   10,    7), M(   12,    7),
        M(    8,   11), M(    4,   17), M(    7,   20), M(    7,   22), M(    2,   21),
        M(   -6,   19), M(    5,   21), M(    7,   18), M(    4,   18), M(    2,   14),
        M(    5,   10), M(   -6,   11), M(  -10,   10), M(   -3,   17), M(    2,   14),
        M(    4,   13), M(    4,   21), M(    6,   22), M(    9,   21), M(    2,   21),
        M(   -1,   19), M(   15,   11), M(    9,   16), M(   -3,   20), M(   -5,   20),
        M(   -7,   16), M(   -9,    6), M(  -15,   10), M(  -10,   23), M(   -5,   15),
        M(   -0,   17), M(   -2,   26), M(    4,   24), M(    9,   22), M(    6,   20),
        M(    0,    0), M(    0,    0), M(    0,    0), M(    0,    0), M(    0,    0),
        M(    0,    0), M(    0,    0), M(    0,    0), M(    0,    0), M(    0,    0),
        M(    0,    0), M(    0,    0), M(    0,    0), M(    0,    0), M(    0,    0),
    },
    {
    
    },
    {
    
    },
    {
    
    },
    {
    
    },
};



// indexed by piece, sameSideCastle, square
EvalScore piece_square_table[6][2][64]{
    {
        {
            
            M(    0,    0), M(    0,    0), M(    0,    0), M(    0,    0),
            M(    0,    0), M(    0,    0), M(    0,    0), M(    0,    0),
            M(   -1,    4), M(   19,   18), M(   12,   38), M(   -5,   43),
            M(   -6,   29), M(   -8,   26), M(  -10,   26), M(  -14,   38),
            M(   -6,   16), M(   -3,   21), M(   -3,   36), M(   -4,   33),
            M(   -2,   22), M(   -8,   25), M(  -14,   27), M(  -14,   35),
            M(  -11,   26), M(   -1,   35), M(    4,   32), M(   17,   25),
            M(   12,   21), M(    8,   23), M(   -8,   40), M(  -12,   47),
            M(    9,   41), M(   15,   50), M(   37,   37), M(   39,   29),
            M(   32,   20), M(   16,   42), M(    9,   56), M(    3,   69),
            M(   17,   67), M(   79,   57), M(  112,   41), M(   70,   33),
            M(   54,   43), M(   50,   74), M(   38,   99), M(   -2,  114),
            M(   64,  143), M(   84,  136), M(  210,   90), M(  215,  102),
            M(  192,  136), M(  188,  166), M(  150,  201), M(  160,  198),
            M(    0,    0), M(    0,    0), M(    0,    0), M(    0,    0),
            M(    0,    0), M(    0,    0), M(    0,    0), M(    0,    0),
        },
        {
            
            M(    0,    0), M(    0,    0), M(    0,    0), M(    0,    0),
            M(    0,    0), M(    0,    0), M(    0,    0), M(    0,    0),
            M(   16,   16), M(   39,   10), M(   23,   24), M(    1,   34),
            M(    1,   38), M(   -1,   40), M(  -10,   46), M(  -13,   47),
            M(   18,   21), M(   21,   19), M(    2,   32), M(   -2,   31),
            M(    4,   32), M(    1,   35), M(  -20,   41), M(  -23,   45),
            M(   26,   43), M(   20,   47), M(   16,   37), M(   16,   32),
            M(   22,   27), M(   16,   32), M(   -8,   43), M(  -28,   46),
            M(   42,   87), M(   39,   79), M(   33,   65), M(   39,   44),
            M(   55,   26), M(   50,   28), M(    3,   49), M(  -15,   48),
            M(   37,  165), M(   80,  155), M(   64,  129), M(   64,   76),
            M(   96,   23), M(  105,   16), M(   77,   26), M(    2,   50),
            M(  227,  247), M(  208,  259), M(  169,  236), M(  211,  172),
            M(  243,   96), M(  263,   46), M(  121,   84), M(   77,   93),
            M(    0,    0), M(    0,    0), M(    0,    0), M(    0,    0),
            M(    0,    0), M(    0,    0), M(    0,    0), M(    0,    0),
        },
    },
    {
        {
            
            M( -108,   22), M(  -77,   45), M(  -68,   46), M(  -68,   65),
            M(  -70,   68), M(  -78,   41), M(  -80,   26), M( -117,   -1),
            M(  -80,   59), M(  -86,   65), M(  -69,   51), M(  -69,   70),
            M(  -66,   70), M(  -84,   52), M(  -99,   56), M( -104,   38),
            M(  -78,   49), M(  -65,   72), M(  -62,   75), M(  -59,   87),
            M(  -65,   86), M(  -78,   64), M(  -81,   49), M(  -95,   18),
            M(  -68,   77), M(  -43,   86), M(  -60,  102), M(  -56,  106),
            M(  -68,  103), M(  -72,   94), M(  -83,   73), M(  -88,   48),
            M(  -59,   73), M(  -60,   85), M(  -41,  103), M(  -63,  114),
            M(  -66,  118), M(  -63,   98), M(  -76,   68), M(  -84,   59),
            M(  -82,   64), M(  -56,   71), M(   -4,   89), M(   -9,   89),
            M(  -40,   99), M(  -57,   97), M(  -80,   66), M( -108,   49),
            M(  -61,   56), M( -109,   69), M(   -9,   51), M(  -28,   84),
            M(  -22,   86), M(  -47,   62), M(  -97,   64), M(  -94,   45),
            M( -201,   -2), M( -168,   77), M( -202,  111), M(  -79,   74),
            M( -114,   79), M( -225,  106), M( -209,   77), M( -284,   14),
        },
        {
            
            M(  -66,  -30), M(  -49,   20), M(  -20,    9), M(  -12,   32),
            M(  -18,   27), M(  -29,    9), M(  -36,   10), M(  -75,    0),
            M(  -37,   11), M(  -43,   30), M(  -18,   13), M(  -14,   30),
            M(   -9,   33), M(  -23,   22), M(  -57,   32), M(  -58,   10),
            M(  -37,    5), M(  -21,   25), M(   -9,   33), M(   -6,   49),
            M(    1,   49), M(  -17,   31), M(  -16,   15), M(  -44,   -2),
            M(  -18,   29), M(    3,   38), M(    1,   58), M(    5,   60),
            M(   14,   57), M(    5,   49), M(   11,   32), M(  -14,   17),
            M(  -22,   34), M(   -4,   33), M(   18,   54), M(   20,   66),
            M(   15,   66), M(   22,   52), M(    7,   27), M(    0,   18),
            M(  -60,   23), M(    6,   21), M(   22,   52), M(   42,   49),
            M(   57,   44), M(   63,   36), M(   17,   10), M(   -9,    2),
            M(  -33,    2), M(  -29,   24), M(   37,   10), M(   66,   35),
            M(   41,   30), M(   32,   10), M(  -38,   15), M(   -7,   -2),
            M( -215,  -31), M( -160,   37), M( -145,   51), M(  -60,   38),
            M(  -41,   21), M( -127,   39), M(  -24,    3), M( -176,  -41),
        },
    },
    {
        {
            
            M(  -52,    9), M(  -64,   24), M(  -55,   25), M(  -57,   39),
            M(  -52,   36), M(  -50,   40), M(  -46,   38), M(  -38,   15),
            M(  -44,   -6), M(  -31,   11), M(  -43,   26), M(  -49,   38),
            M(  -51,   44), M(  -46,   33), M(  -40,   16), M(  -46,   14),
            M(  -35,   36), M(  -38,   43), M(  -40,   50), M(  -43,   54),
            M(  -45,   53), M(  -43,   49), M(  -39,   39), M(  -50,   28),
            M(  -41,   33), M(  -46,   47), M(  -48,   58), M(  -31,   59),
            M(  -30,   63), M(  -43,   58), M(  -45,   41), M(  -61,   25),
            M(  -60,   48), M(  -35,   53), M(  -35,   59), M(  -25,   68),
            M(  -12,   62), M(  -39,   55), M(  -39,   46), M(  -69,   43),
            M(  -38,   47), M(  -23,   59), M(   -7,   62), M(   -7,   54),
            M(  -25,   55), M(  -24,   54), M(  -51,   57), M(  -63,   40),
            M(  -81,   50), M(  -49,   55), M(  -33,   49), M(  -53,   57),
            M(  -74,   60), M(  -57,   58), M(  -63,   59), M( -108,   58),
            M( -103,   56), M(  -89,   52), M( -189,   69), M( -147,   69),
            M( -170,   79), M( -183,   74), M( -122,   70), M( -116,   66),
        },
        {
            
            M(   23,  -15), M(   -6,    0), M(   12,   -0), M(    3,    7),
            M(    4,    7), M(   -2,    3), M(    1,    6), M(    4,  -12),
            M(   27,  -23), M(   57,  -16), M(   32,   -5), M(   24,    2),
            M(    8,    6), M(    7,   -0), M(    2,  -14), M(    9,  -19),
            M(   29,   -6), M(   44,    6), M(   48,   10), M(   27,   11),
            M(   23,   16), M(   10,   11), M(   12,    2), M(    3,   -3),
            M(   16,   -5), M(   32,   11), M(   31,   19), M(   55,   21),
            M(   32,   22), M(   24,   16), M(   20,    2), M(   17,   -7),
            M(    8,   14), M(   31,   15), M(   36,   27), M(   52,   29),
            M(   71,   21), M(   34,   11), M(   44,   11), M(   15,   -1),
            M(    1,   12), M(   33,   21), M(   38,   24), M(   49,   23),
            M(   79,   11), M(   89,   10), M(   60,    3), M(   29,   -2),
            M(  -39,   23), M(  -15,   33), M(   11,   28), M(  -20,   28),
            M(   12,   19), M(   55,    4), M(   25,   11), M(  -28,    2),
            M(  -39,   36), M(  -82,   34), M(  -84,   32), M(  -88,   38),
            M( -123,   32), M( -103,   26), M(   28,    7), M(  -14,   24),
        },
    },
    {
        {
            
            M( -103,   62), M(  -77,   71), M(  -76,   79), M(  -78,   73),
            M(  -77,   75), M(  -85,   84), M(  -91,   81), M(  -94,   77),
            M( -160,   80), M(  -84,   66), M(  -77,   68), M(  -86,   75),
            M(  -86,   77), M(  -96,   84), M(  -99,   77), M( -131,   84),
            M( -106,   71), M(  -72,   87), M(  -87,   89), M(  -91,   85),
            M(  -91,   87), M( -104,   94), M(  -97,   96), M( -110,   85),
            M(  -98,   95), M(  -73,  103), M(  -88,  109), M(  -91,  105),
            M(  -90,  108), M( -100,  116), M( -104,  117), M( -104,  102),
            M(  -65,  107), M(  -46,  101), M(  -44,  107), M(  -49,  106),
            M(  -41,  108), M(  -67,  117), M(  -77,  114), M(  -90,  116),
            M(  -47,  111), M(   10,   91), M(    3,  104), M(  -10,   96),
            M(  -29,  106), M(  -56,  120), M(  -46,  109), M(  -91,  125),
            M(  -64,  121), M(  -61,  123), M(  -13,  106), M(  -58,  135),
            M(  -58,  136), M(  -71,  136), M(  -95,  140), M(  -89,  133),
            M(  -28,  128), M(  -46,  136), M(  -38,  137), M(  -85,  140),
            M(  -96,  145), M( -105,  151), M(  -76,  140), M(  -74,  135),
        },
        {
            
            M(  -46,   33), M(  -20,   29), M(  -10,   31), M(   -8,   26),
            M(   -6,   21), M(   -1,   26), M(    2,   22), M(  -21,   23),
            M(  -94,   38), M(  -41,   23), M(  -24,   27), M(  -25,   32),
            M(  -18,   29), M(  -11,   24), M(   -3,   15), M(  -52,   30),
            M(  -47,   28), M(  -11,   33), M(  -32,   40), M(  -27,   38),
            M(  -28,   36), M(  -20,   36), M(   -9,   36), M(  -26,   27),
            M(  -30,   49), M(   -2,   50), M(  -23,   61), M(  -21,   57),
            M(  -18,   49), M(  -16,   53), M(  -11,   51), M(  -23,   42),
            M(    0,   60), M(   10,   56), M(   26,   53), M(   34,   55),
            M(   31,   47), M(   22,   53), M(   27,   43), M(   17,   44),
            M(    9,   61), M(   59,   41), M(   43,   59), M(   59,   47),
            M(   68,   42), M(   62,   46), M(   79,   33), M(   26,   50),
            M(   11,   67), M(   18,   67), M(   29,   68), M(   21,   80),
            M(   29,   69), M(   62,   47), M(   17,   60), M(   24,   54),
            M(   62,   53), M(   33,   70), M(   16,   80), M(   -6,   85),
            M(    7,   77), M(   71,   57), M(   59,   58), M(   33,   67),
        },
    },
    {
        {
            
            M( -157,   70), M( -148,   50), M( -141,   67), M( -133,   84),
            M( -132,   98), M( -139,   89), M( -145,   96), M( -144,  106),
            M( -155,   78), M( -130,   47), M( -124,   47), M( -132,  104),
            M( -134,  113), M( -132,   80), M( -139,   96), M( -148,  102),
            M( -125,   93), M( -121,  107), M( -134,  126), M( -139,  113),
            M( -142,  113), M( -142,  123), M( -136,  111), M( -149,  105),
            M( -122,  129), M( -125,  130), M( -136,  136), M( -150,  152),
            M( -155,  153), M( -151,  122), M( -147,  133), M( -151,  118),
            M( -132,  133), M( -123,  166), M( -145,  166), M( -157,  158),
            M( -165,  160), M( -163,  126), M( -163,  152), M( -163,  138),
            M( -172,  152), M( -129,  160), M( -141,  150), M( -136,  144),
            M( -155,  124), M( -165,  125), M( -167,  135), M( -175,  153),
            M( -142,  167), M( -197,  218), M(  -92,  126), M( -215,  193),
            M( -206,  169), M( -171,  136), M( -216,  181), M( -177,  158),
            M( -110,  117), M( -145,  158), M( -131,  136), M( -179,  151),
            M( -162,  138), M( -165,  144), M( -160,  145), M( -186,  162),
        },
        {
            
            M(   29,  -63), M(   48,  -88), M(   61,  -88), M(   59,  -45),
            M(   61,  -49), M(   56,  -60), M(   52,  -27), M(   58,  -49),
            M(   20,  -50), M(   50,  -55), M(   81,  -90), M(   73,  -30),
            M(   65,  -34), M(   74,  -65), M(   77,  -59), M(   68,  -49),
            M(   38,  -25), M(   64,  -21), M(   62,   -4), M(   60,  -17),
            M(   58,  -16), M(   67,  -22), M(   77,  -39), M(   77,  -49),
            M(   46,   -9), M(   57,   11), M(   43,   17), M(   52,   35),
            M(   50,   19), M(   64,   -2), M(   73,  -20), M(   84,  -45),
            M(   49,    4), M(   36,   34), M(   37,    8), M(   42,   33),
            M(   60,   22), M(   67,    6), M(   92,   -4), M(   75,  -34),
            M(   38,   25), M(   56,  -11), M(   60,   -9), M(   51,    1),
            M(   79,    8), M(   59,   22), M(   92,  -31), M(   55,  -30),
            M(   41,    7), M(    2,   47), M(   42,    8), M(   -3,   49),
            M(  -18,   70), M(   98,   -8), M(   30,   18), M(   58,  -30),
            M(   52,   -1), M(   58,    7), M(   48,    2), M(   32,   19),
            M(   19,   26), M(  167,  -74), M(   50,  -13), M(   73,  -42),
        },
    },
    {
        {
            
            M(  168, -190), M(  259,  -82), M(  172,  -59), M(  223,  -37),
            M(  203,  -57), M(  134,  -57), M(  136,  -61), M(  155, -186),
            M(  100,  -79), M(  188,  -25), M(  237,  -41), M(  261,  -48),
            M(  231,  -47), M(  247,  -42), M(  117,  -17), M(  158,  -91),
            M(  109,  -41), M(  239,  -27), M(  274,  -35), M(  280,  -41),
            M(  273,  -42), M(  290,  -36), M(  220,  -26), M(  132,  -52),
            M(   62,  -32), M(  208,  -40), M(  215,  -25), M(  176,  -16),
            M(  191,  -18), M(  213,  -23), M(  169,  -32), M(   35,  -32),
            M(   17,  -45), M(  133,  -29), M(  160,  -16), M(  105,   -1),
            M(  128,   -0), M(  128,   -7), M(  124,  -18), M(    1,  -33),
            M(   -8,  -27), M(   34,   -9), M(   58,   -4), M(   43,    9),
            M(   60,   11), M(   57,    5), M(   31,    1), M(  -17,   -9),
            M(   52,  -25), M(   22,   -2), M(   12,    7), M(  -40,   18),
            M(   -6,   16), M(   -5,   22), M(   21,    6), M(   28,  -13),
            M(   58,  -71), M(   47,  -20), M(   19,   -2), M(   -3,  -15),
            M(    4,  -21), M(  -10,    8), M(   48,  -12), M(   49,  -63),
        },
        {
            
            M(  192, -182), M(  223,  -64), M(  152,  -44), M(  182,  -22),
            M(  150,  -42), M(  106,  -44), M(  114,  -49), M(  175, -188),
            M(   80,  -63), M(  169,  -16), M(  204,  -31), M(  246,  -44),
            M(  216,  -42), M(  242,  -36), M(   88,   -5), M(  129,  -81),
            M(  100,  -32), M(  217,  -19), M(  250,  -27), M(  259,  -35),
            M(  263,  -36), M(  280,  -29), M(  193,  -15), M(   97,  -39),
            M(   32,  -21), M(  185,  -32), M(  200,  -20), M(  164,  -12),
            M(  175,  -13), M(  206,  -18), M(  147,  -24), M(   20,  -24),
            M(   11,  -37), M(  122,  -23), M(  152,  -12), M(   95,    3),
            M(  119,    4), M(  124,   -4), M(  122,  -15), M(   -1,  -29),
            M(   -7,  -20), M(   33,   -6), M(   57,   -2), M(   42,   12),
            M(   58,   14), M(   58,    7), M(   42,    1), M(   -8,   -9),
            M(   41,  -17), M(   26,   -1), M(   17,    6), M(  -38,   19),
            M(   -3,   17), M(   -4,   22), M(   27,    5), M(   38,  -14),
            M(   44,  -68), M(   41,  -23), M(   14,   -3), M(  -14,  -15),
            M(   -3,  -23), M(  -18,    6), M(   50,  -17), M(   55,  -68),
        },
    },
};

// indexed by wking, bking, piece, square
EvalScore piece_kk_square_tables[64][64][14][64];

void psqt_init() {
    for(Square wKingSq = 0; wKingSq < 64; wKingSq++){
        for(Square bKingSq = 0; bKingSq < 64; bKingSq++){
            
            bool   wKSide            = (fileIndex(wKingSq) > 3 ? 0 : 1);
            bool   bKSide            = (fileIndex(bKingSq) > 3 ? 0 : 1);
            bool   sameSideCastle    = wKSide == bKSide;
            
            // pawn, knight, bishop, rook, queen
            for(Piece p = 0; p < 5; p++){
                for(Square sq = 0; sq < 64; sq++){

                    piece_kk_square_tables[wKingSq][bKingSq][p]  [sq] =
                          + piece_square_table              [p][!sameSideCastle][pst_index_white(sq, wKSide)]
                          + piece_values                    [p]
                          + piece_our_king_square_table     [p]     [pst_index_relative_white(sq, wKingSq)]
                          + piece_opp_king_square_table     [p]     [pst_index_relative_white(sq, bKingSq)];

                    piece_kk_square_tables[wKingSq][bKingSq][p+8][sq] =
                          - piece_square_table              [p][!sameSideCastle][pst_index_black(sq, bKSide)]
                          - piece_values                    [p]
                          - piece_our_king_square_table     [p]     [pst_index_relative_black(sq, bKingSq)]
                          - piece_opp_king_square_table     [p]     [pst_index_relative_black(sq, wKingSq)];
                }
            }

            // kings
            for(Square sq = 0; sq < 64; sq++){
                piece_kk_square_tables[wKingSq][bKingSq][WHITE_KING][sq]
                    = + piece_square_table[KING][0][pst_index_white_s(sq)];
                piece_kk_square_tables[wKingSq][bKingSq][BLACK_KING][sq]
                    = - piece_square_table[KING][0][pst_index_black_s(sq)];
            }
            
        }
    }
}