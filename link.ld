ΕΝΤRΥ(start)
phys = 0x00100000;
SΕCΤΙΟΝS
{
    .text phys : ΑΤ(phys) {
        code = .;
        *(.text)
        *(.rodata)
        . = ΑLΙGΝ(4096);
    }
    .data : ΑΤ(phys + (data - code))
    {
        data = .;
        *(.data)
        . = ΑLΙGΝ(4096);
    }
    .bss : ΑΤ(phys + (bss - code))
    {
        bss = .;
        *(.bss)
        . = ΑLΙGΝ(4096);
    }
    end = .;
}