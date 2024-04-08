bool sprawdz_kierunek(rodzaj_planszy plansza, int wier, int kol, int dwier, int dkol, int tura) {
    int i, j;
    int zeton_wroga = (tura == TURA_CZARNY) ? BIALY : CZARNY;


//OK, jesli pole nie jest puste, false od razu
    if (plansza[wier][kol] != 0) {
        return false;
    }
    
   
//OK, jesli krok w danym kierunku wyprowadzi nas poza plansze, false od razu dla tego kierunku
    if (!w_zakresie(wier + dwier) || !w_zakresie(kol + dkol)) {
        return false;
    }

    // jesli obok w danym  kierunku jest wlasny zeton lub puste pole, false od razu
    if (plansza[wier + dwier][kol + dkol] == tura || plansza[wier + dwier][kol + dkol] == 0) {
	return false;
	}
	
	
    for (i = wier + dwier, j = kol + dkol; w_zakresie(i) && w_zakresie(j) && plansza[i][j] == zeton_wroga; i += dwier, j += dkol) {
        if (plansza[i][j] == 0) {
     
            return false;
        }
    }
 //plansza[i][j] != zeton_wroga
    if (!w_zakresie(i) || !w_zakresie(j)) {
  
        return false;
    }
    

    return true;
}



bool checkdir(const board_type& board, int row, int col, int drow, int dcol, char turn)
{
    int i, j;
    
//OK, jesli krok w danym kierunku wyprowadzi nas poza plansze, false od razu dla tego kierunku
    if (!inside_bounds(row + drow) || !inside_bounds(col + dcol))
        return false;

//OK, pole obok wlasne lub puste lub aktualne pole puste od razu false
    if(board[row + drow][col + dcol] == turn || board[row + drow][col + dcol] == '-' || board[row][col] != '-')
        return false;
        
        

    for(i = row + drow, j = col + dcol; inside_bounds(i) && inside_bounds(j) && board[i][j] != turn; i += drow, j += dcol)
        if(board[i][j] == '-')
            return false;
    if(!inside_bounds(i) || !inside_bounds(j))
        return false;

    return true;
}





