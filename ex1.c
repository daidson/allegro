/***************************************************************************
 *   ex1.c                                    Version 20170817.185801      *
 *                                                                         *
 *   Salvalle.c                                                            *
 *   Copyright (C) 2017         by Daidson Fonseca Alves                   *
 ***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; version 2 of the License.               *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************
 *   To contact the author, please write to:                               *
 *   Daidson Fonseca Alves                                                 *
 *   Email: daidson.alves@gmail.com                                        *
 *   Webpage: http://www.github.com/daidson                                *
 *   Phone: +55 (81) 99954-6310                                            *
 ***************************************************************************/

/*
 * Instrucoes para compilar:
 * $gcc ex1.c -o ex1.x -Wall 'allegro-config --cflags --libs'
 * opcoes extras: -ansi -pedantic-errors
 */

/* ---------------------------------------------------------------------- */
/* includes */

#include <stdio.h> /* Standard I/O functions */
#include <allegro.h> /* graphic library used in the exercise */

/* color definitions */
#define CORBRANCO (makecol(255,255,255))
#define CORPRETO 1
#define CORCINZA (makecol(160,160,160))
#define CORAZUL (makecol(0,0,160))
#define CORVERDE (makecol(0,255,0))
#define CORAMARELO (makecol(255,255,100))
#define CORVERMELHO (makecol(255,0,0))

/* image file name */
#define IMAGENAME "teste.bmp"

int main(void)
{
    BITMAP *buff;
    PALETTE pal;

    if(install_allegro(SYSTEM_NONE, &errno, atexit)!=0)
        exit(EXIT_FAILURE);

    set_color_depth(16);
    get_palette(pal);

    //Create a buffer for smooth animation.
    buff = create_bitmap(320,240);
    if(buff == NULL)
    {
        printf("Could not create buffer!\n");
        exit(EXIT_FAILURE);
    }

    /* circle(buff, 160, 120, 100, CORAMARELO);
    textprintf_ex(buff, font, 50, 50, CORVERDE, CORPRETO, "Teste do circulo."); */
    
/*    triangle(buff, 10, 10, 10, 50, 50, 50, CORVERDE);
    triangle(buff, 50, 50, 50, 90, 90, 90, CORVERDE); */

    circle(buff, 20, 20, 10, CORBRANCO);
    circlefill(buff, 50, 50, 25, CORCINZA);
    rect(buff, 70, 70, 90, 90, CORAZUL);
    rectfill(buff, 100, 100, 120, 120, CORVERDE);
    line(buff, 130, 130, 150, 150, makecol(255, 0, 0));
    line(buff, 130, 130, 170, 130, makecol(255, 0, 0));
    line(buff, 170, 130, 150, 150, makecol(255, 0, 0));
    floodfill(buff, 150, 140, makecol(255, 255, 0));
    triangle(buff, 200, 200, 200, 220, 220, 210, makecol(213, 79, 40));

    save_bitmap(IMAGENAME, buff, pal);
    destroy_bitmap(buff);
    allegro_exit();

    printf("Imagem %s salva com sucesso!\n", IMAGENAME);

    return EXIT_SUCCESS;
}

/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20160612.142044      */

