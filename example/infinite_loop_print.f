: INFINITY_LOOP_PRINT
    0
    BEGIN
        ." To je neskoncna zanka." CR
        0= 
        IF
            ." Lihi korak!" CR
            1
        ELSE
            ." Sodi korak!" CR
            0
        THEN
    AGAIN
;

.( EXE: INFINITY_LOOP_PRINT ) CR

2 TRACE-LEVEL !

INFINITY_LOOP_PRINT
