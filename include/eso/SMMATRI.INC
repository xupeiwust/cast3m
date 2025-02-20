*    -INC SMMATRI
*
      SEGMENT       MMATRI
        INTEGER     IJMAX,IDIAG,IGEOMA,IINCPO,IIDUA,IIMIK
        INTEGER     INEG,IDNORM,IILIGN,IILIGS,NENS,IHARK,IASLIG,IASDIA
        INTEGER     IDUAPO,IHARDU,IDNORD
        REAL*8      PRCHLV
      ENDSEGMENT
      POINTEUR      MATR1.MMATRI
*
      SEGMENT       LLIGN
        REAL*8      XXVA(LLVVA)
        INTEGER     IPPO(NA+1),IMMMM(NA),LINC(LLVVA),LDEB(NA),NJMAX
      ENDSEGMENT
*
      SEGMENT       LIGN
        REAL*8      VAL(NVALL)
        INTEGER     IMMM(NA),IPPVV(NA+1),IVPO(2*NBPAR),IMM,IPREL,IDERL
        INTEGER     IML
      ENDSEGMENT
      POINTEUR      LIG1.LIGN
*
      SEGMENT       MINCPO
        INTEGER     INCPO(MAXI,NNOE)
      ENDSEGMENT
      POINTEUR      MIPO1.MINCPO
*
      SEGMENT       MIMIK
        CHARACTER*4 IMIK(0)
      ENDSEGMENT
      POINTEUR      MDES1.MIMIK
*
      SEGMENT       MHARK
        INTEGER     IHAR(0)
      ENDSEGMENT
      POINTEUR      MHAR1.MHARK
*
      SEGMENT       MDIAG
        REAL*8      DIAG(INC)
      ENDSEGMENT
      POINTEUR      MDIA1.MDIAG
*
      SEGMENT       MDNOR
        REAL*8      DNOR(INC)
      ENDSEGMENT
      POINTEUR      MDNO1.MDNOR
*
      SEGMENT       MILIGN
        INTEGER     ILIGN(NNOE),ITTR(INC),IPNO(INC)
        INTEGER     LCARA(3,NNOE)
      ENDSEGMENT
      POINTEUR      MILIG1.MILIGN
*
      SEGMENT       MIDUA
        CHARACTER*4 IDUA(0)
      ENDSEGMENT
      POINTEUR      MDUA1.MIDUA
*
C
C SEGMENT MILIGN:
C  ****  ILIGN EST UN TABLEAU DE POINTEUR SUR SEGMENT LIGN
C  ****  ITTR INDIQUE PAR 1 OU 0 SI L'INCONNUE EST DE TYPE LAGRANGE
C  ****  IPNO INDIQUE LE NUMERO DU NOEUD DE L'INCONNUE
C SEGMENT LIGN:
C  ****  VAL DONNE LES VALEURS DE LA MATRICE
C  ****  VAL VA ETRE STOCKE SOUS FORME COMPACTEE APRES L'INVERSION
C  ****  IMMM INDIQUE PAR 1 OU 0 SI UN MOUVEMENT D'ENSEMBLE A ETE
C  ****  DETECTE SUR L'INCONNUE.
C  ****  IPPVV INDIQUE LA POSITION DES DEBUT DE LIGNE DANS IVPO
C  ****  IVPO INDIQUE 2: LA POSITION DES DEBUTS DE GROUPE DANS VAL
C  ****               1:  LEUR ADDRESSES DANS LA LIGNE
C  ****  IMM INDIQUE LA PREMIER LIGNE CONCERNEE PAR L'INVERSION DES
C  ****  LIGNES INFERIEURES
C  ****  IML indique la premiere inconnue des lignes du noeud
C  ****  IPREL,IDERL:NUMERO DE LA PREMIERE,DERNIERE INCONNUE DU SEGMENT
C  ****  IML est aussi dans LCARA(1, IPREL dans LCARA(2, IDERL dans LCARA(3,
C  ****   pour minimiser les fautes de cache dans chole3i
C SEGMENT LLIGN :
C  ****  CE SEGMENT, UTILE AU COURS DE LA TRIANGULARISATION, EST DETRUIT
C  ****  EN FIN DE TRAVAIL
C  ****
C SEGMENT MMATRI :
C  ****  IJMAX EST LA LONGUEUR DE LA PLUS GRANDE LIGNE
C  ****  IDIAG POINTEUR SUR LE SEGMENT MDIAG
C  ****  IGEOMA POINTEUR SUR L'OBJET GEOMETRIQUE
C  ****  IIDUA POINTEUR SUR LE SEGMENT MIDUA
C  ****  IINCPO POINTEUR SUR LE SEGMENT MINCPO
C  ****  IIMIK  POINTEUR SUR LE SEGMENT MIMIK
C  ****  INEG  NOMBRE DE TERMES DIAGONAUX NEGATIFS.
C  ****  IDNORM POINTEUR SUR MDNOR CONTENANT VALEUR DE NORMALISATION
C  ****  INCPOS(I,K)=J LA I EME INCONNUE DU NOEUD LOCAL K EST EN J EME
C                    POSITION DANS LA MATRICE
C  ****  IMIK(I) DONNE LE TYPE DE L'INCONNUE I.
C  ****  IDUA(I) DONNE LE TYPE DE L'INCONNUE DUALE DE LA I EME

************************************************************************
