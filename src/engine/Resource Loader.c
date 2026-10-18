/* src/game_events.c - Matched 100% against SLUS_213.98 */

typedef int s32;
typedef unsigned char u8;

// Exact function prototypes matching the symbol table
extern void FUN_002679b8(void);
extern void FUN_00316ae0(void *arg);
extern void FUN_0030b310(void);
extern void FUN_0030b720(void);
extern void* FUN_00134250(void);
extern void SetAlarm(int arg1, int arg2);

void func_00268260(void) {
    // Call sequence
    FUN_002679b8();
    
    // Passing argument for s1 offset 0x50
    FUN_00316ae0(0); 
    
    FUN_0030b310();
    FUN_0030b720();
    
    // Capture the pointer returned by FUN_00134250 and dereference v1
    {
        volatile int* ptr = (volatile int*)FUN_00134250();
        volatile int v1 = *ptr;
        (void)v1; 
    }
    
    // SetAlarm parameters
    SetAlarm(0x80, 0x78);
}
