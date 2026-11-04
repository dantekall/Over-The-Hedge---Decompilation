

---





---


---

## Decompilation process

Let's imagine that you chose the function `heather_play_dead` as an example (this is not in the game, I just used this as an example)

Let's begin by first taking a look at the info we have for this function:

* Debug info for the function:


* Name: `heather_play_dead`


* Signature: `int HeatherController::heather_play_dead(POSSUM_STATE* state)`


* Arguments:


* `$a0` -> `POSSUM_STATE *state`




* Local variables:


* `$a1` -> `int faked_death`






* Disassembly:



```mipsasm
    lw    $v1, 0x140($a0)
    lw    $v0, 0x10($a0)
    beqz  $v0, l_30
    negu  $a1, $v1
    bnezl $v1, l_24
    lbu   $v1, 0x18($a0)
    b     l_30
    move  $a1, $zero
l_24:
    lbu   $v0, 0x144($a0)
    xor   $v0, $v0, $v1
    movz  $a1, $zero, $v0
l_30:
    jr    $ra
    move  $v0, $a1

```

Given the above, you can start in two ways:

1. Let a decompiler give you a head start (Ghidra, m2c):


* Pros:


* a.) Works great with small functions.


* b.) Ghidra can figure GCC optimizations nicely.


* c.) m2c is designed with matching decomp in mind.




* Cons:


* a.) Not efficient for big functions.


* b.) m2c isn't very good at figuring GCC optimizations.


* c.) Ghidra isn't built for matching decomp—its pseudocode won't match most of the time.






2. Translate assembly by hand:


* Pros:


* a.) Very efficient regardless of the function.


* b.) You will have a better view of the control flow.




* Cons:


* a.) Time-consuming depending on length and complexity.


* b.) Requires previous knowledge of compiler optimizations.







I strongly recommend option 1 for starting and later transitioning to option 2.

---

## Translating Heather's Function

Following the instruction-by-instruction translation workflow (mapping GPRs, struct offsets, handling branch delay slots, and likely branches), we map out the initial pseudocode.

After stepping through branch cleanup and utilizing the debug info for `HeatherController::heather_play_dead`, we arrive at the final C++ code:

```cpp
int HeatherController::heather_play_dead(POSSUM_STATE* state) {
    int faked_death = -state->fright_level;
    if (state->is_alarmed != 0) {
        if (state->fright_level == 0) {
            faked_death = 0;
        } else if (state->pulse_check == state->target_pulse) {
            faked_death = 0;
        }
    }
    return faked_death;
}

```

This clean C++ method compiles and matches the original MIPS binary perfectly!

---

## Making a decomp.me scratch

If you need some help with a function or you just want to decomp from the browser, you'll want to make a `decomp.me` scratch:

1. Obtain the disassembly using the project's assembly tools.


2. Go to the `decomp.me` website and make a [new scratch](https://decomp.me/new), using the appropriate PS2 C++ preset.


3. Paste the disassembly into the **Target assembly** box.


4. Fill in the necessary context with base types and defines (`u_char`, `u_short`, `u_int`, `NULL`, etc.).


5. Click the **Create scratch** button and get matching!
