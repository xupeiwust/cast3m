* -INC SMCHARG
*
*
*     OBJET DE TYPE 'CHARGEME'
      SEGMENT MCHARG
       INTEGER KCHARG(N)
       CHARACTER*8 CHANAT(N)
       CHARACTER*4 CHANOM(N)
       CHARACTER*4 CHAMOB(N)
       CHARACTER*4 CHALIE(N)
      ENDSEGMENT
       POINTEUR MCHAR1.MCHARG,MCHAR2.MCHARG
*
      SEGMENT ICHARG
       CHARACTER*8 CHATYP
       INTEGER ICHPO1,ICHPO2,ICHPO3,ICHPO4,ICHPO5,ICHPO6,ICHPO7
      ENDSEGMENT
       POINTEUR ICHAR1.ICHARG,ICHAR2.ICHARG
*
*     KCHARG(I) : POINTEUR SUR LE SEGMENT ICHARG
*     CHANAT    : MOT INDIQUANT LA NATURE DU CHARGEMENT: FORCE OU DEPLA
*     CHANOM    : MOT INDIQUANT LE NOM DU CHARGEMENT
*     CHAMOB    : MOT INDIQUANT L'OPTION DE MOBILITE DU CHARGEMENT
*     CHATYP    : TYPE DE L OBJET : CHPOINT MCHAML ou TABLE
*     ICHPO1    : POINTEUR SUR L OBJET PRECEDEMMENT DEFINI
*     ICHPO2    : POINTEUR SUR UN OBJET LISTREEL: INSTANTS T ou TABLE
*     ICHPO3    : POINTEUR SUR UN OBJET LISTREEL: AMPLITUDES AU TEMPS T
*     ICHPO4    : POINTEUR SUR UN OBJET POINT ou CHPOINT
*     ICHPO5    : POINTEUR SUR UN OBJET POINT ou MAILLAGE
*     ICHPO6    : POINTEUR SUR UN OBJET LISTREEL: INSTANTS T
*     ICHPO7    : POINTEUR SUR UN OBJET LISTREEL: VITESSES AU TEMPS T
*
