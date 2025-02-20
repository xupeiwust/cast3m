
C* -INC SIZFFB   DEBUT **************************************************
C     -------------------------------------------------------------------
C
C     -------------- SEGMENT MODIFICATI ----------
C     7/7/1988  MODIFICATION  : PASSAGE EN DOUBLE PRECISION
C
      SEGMENT IZFFM
      CHARACTER*8 NOMEL
      REAL*8      FN(NP,NPG),GR(NES,NP,NPG),PG(NPG),XREF(NES,NP)
      POINTEUR    KTP(N1).IZFFM,KZHR(N2).IZHR
      ENDSEGMENT

      SEGMENT IZHR
      REAL*8      HR(IES,NP,NPG),PGSQ(NPG),RPG(NPG)
      REAL*8      XYZ(IES,NP),AJ(IES,IES,NPG)
      ENDSEGMENT
C
C     IZFFM PORTA INFORMAZIONI SULLO ELEMENTO DI RIFERIMENTO
C     IZHR PORTA INFORMAZIONI SULLO ELEMENTO REALE
C
C     FN      = FUNZIONI DI FORMA
C     GR      = GRADIENTE DELLE FUNZIONI DI FORMA NEL SISTEMA
C               DI RIFERIMENTO LOCALE
C     PG      = PESI DELLE FORMULE DI INTEGRAZIONE
C     XREF    = Coordonnées des noeuds de l'élément de référence
C     KTP     = POINTEUR DI SEGMENT/IZFFM/
C     KZHRB   = POINTEUR DI SEGMENT/IZHR/
C     NOMEL*D = NOME DELLO ELEMENTO
C
C     HR      = GRADIENTE DELLE FUNZIONI DI FORMA NEL SISTEMA
C               DI RIFERIMENTO GLOBALE
C     PGSQ    = PESO DI INTEGRAZIONE PER ELEMENTO DI AREA
C               ( PGSQ=PG*DET(J) )
C     RPG     = RAGGIO DEI PUNTI DI INTEGRAZIONE (AXISIMMETRIC)
C     XYZ     = COORDINATE DEI NODI
C     AJ      = JACOBIANO
C
C     NP      = NUMERO DEI NODI DELLO ELEMENTO
C     NPG     = NUMERO DEI PUNTI DI INTEGRAZIONE
C     NES     = NUMERO DELLE DIMENSIONI DELLO ELEMENTO
C               DI RIFERIMENTO
C     IES     = NUMERO DELLE DIMENSIONI DELLO ELEMENTO REALE
C     N1      = NUMERO DI SEGMENT/IZFFM
C     N2      = NUMERO DI SEGMENT/IZHR
C
C     -------------------------------------------------------------------
C* -INC SIZFFB   FIN   **************************************************

