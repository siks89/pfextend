: FINITE_LOOP
    1
    1000 1
    DO
        ." To ni neskoncna zanka." CR
        0= 
        IF
            ." Lihi korak!" CR
            1
        ELSE
            ." Sodi korak!" CR
            0
        THEN
    LOOP
;

.( EXE: FINITE_LOOP) CR

2 TRACE-LEVEL !

FINITE_LOOP
