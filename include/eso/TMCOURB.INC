*           -INC TMCOURB
*
*     INFORMATIONS NECESSAIRES POUR LA CREATION D'UN OBJET "MAILLAGE"
*     CORRESPONDANT A UNE COURBE POLYNOMIALE D'EQUATION:
*                         2       3
*     P(U) = P0 + U.P1 + U .P2 + U .P3 + ...
*
      SEGMENT,MCOURB
         INTEGER NLMCOU,PT1COU,PT2COU,LI1COU,LI2COU,ND1COU
         REAL D1COU,D2COU
         REAL*8 U1COU,U2COU,UCOU(LONG)
         LOGICAL REGCOU
         INTEGER ICOFCO
      ENDSEGMENT
      SEGMENT,MCOFCO
         REAL*8 COFCOU(N,IDIM)
      ENDSEGMENT
*
*     NLMCOU = NOMBRE D'ELEMENTS DE LA COURBE.
*     PT1COU = POINT INITIAL DE LA COURBE.
*     PT2COU = POINT INITIAL DE LA COURBE.
*     LI1COU = LIGNE A RACCORDER EN TETE DE LA COURBE.
*     LI2COU = LIGNE A RACCORDER A LA FIN DE LA COURBE.
*     ND1COU = DEGRE + 1  DES POLYNOMES.
*     U1COU  = BORNE INFERIEURE DU PARAMETRE "U" DU POLYNOME DE LA
*              COURBE.
*     U2COU  = BORNE SUPERIEURE DU PARAMETRE "U" DU POLYNOME DE LA
*              COURBE.
*     UCOU() = VALEURS DU PARAMETRE DES POINTS INTERIEURS DE LA COURBE
*              (UTILISE PAR LES OPERATEURS DE SURFACES POLYNOMIALES).
*              RANGEMENT EN ORDRE MONOTONE:
*              - UCOU(1) POUR LE POINT PROCHE DE "PT1COU",
*              - UCOU(LONG) POUR LE POINT PROCHE DE "PT2COU".
*
*     D1COU  = LONGUEUR DE MAILLE EN DEBUT DE COURBE.
*     D2COU  = LONGUEUR DE MAILLE EN FIN DE COURBE.
*     REGCOU = .TRUE. SI DECOUPAGE REGULIER SELON L'ABSCISSE CURVILIGNE
*              (ET NON PAS SELON LE PARAMETRE "U").
*
*     ICOFCO = VALEUR DU POINTEUR DU SEGMENT "MCOFCO".
*
*     COFCOU = COEFFICIENTS REELS DES EQUATIONS POLYNOMIALES DES
*              ABSCISSES, ORDONNEES ET (EVENTUELLEMENT) COTES DES POINTS
*              DE LA COURBE (EN COMMENCANT PAR LE DEGRE 0).
*
*     NB: POUR AVOIR LES COORDONNEES DES EXTREMITES DE LA COURBE, IL
*         FAUT PASSER PAR "PT1COU" (RESP. "PT2COU") ET "XCOOR" (SEGMENT
*         "MCOORD")
*         ET NON PAS "U1COU" (RESP. "U2COU") ET LE POLYNOME ASSOCIE A
*         LA COURBE.
*
*     NB: IL EST PERMIS D'UTILISER LA LONGUEUR DE "UCOU" POUR CONNAITRE
*         LE NOMBRE DE POINTS INTERIEURS DE LA COURBE.
*         EN CONTRE-PARTIE, IL EST INTERDIT DE MODIFIER LA DEFINITION DE
*         "UCOU".
*
