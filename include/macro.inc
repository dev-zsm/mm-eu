# Macros used by splat/spimdisasm output.
.macro glabel label
    .global \label
    .type \label, @function
    \label:
.endm

.macro dlabel label
    .global \label
    \label:
.endm

.macro endlabel label
    .size \label, . - \label
.endm

.macro enddlabel label
    .size \label, . - \label
.endm

# Marks a function not yet matched by C; no effect on the output.
.macro nonmatching label, size=1
.endm

# Alternate (non-function) label inside code.
.macro alabel label
    .global \label
    \label:
.endm
