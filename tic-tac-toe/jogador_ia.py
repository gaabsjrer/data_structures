# -*- coding: utf-8 -*-
from random import randint

from jogador import Jogador
from tabuleiro import Tabuleiro

class JogadorIA(Jogador):
    def __init__(self, tabuleiro : Tabuleiro, tipo : int):
        super().__init__(tabuleiro, tipo)

    def getJogada(self) -> (int, int):
        #R1
        for i in range(3):
            totais = [0,0,0,0]
            pos_vaziah = []
            pos_vaziav = []
            pos_vaziadp = []
            pos_vaziads = []

            for j in range(3):
                #linhas
                totais[0] += self.matriz[i][j]
                if self.matriz[i][j] == Tabuleiro.DESCONHECIDO:
                    pos_vaziah.append((i,j))
                #colunas
                totais[1] += self.matriz[j][i]
                if self.matriz[j][i] == Tabuleiro.DESCONHECIDO:
                    pos_vaziav.append((j,i))
                #diagonal principal
                totais[2] += self.matriz[j][j]
                if self.matriz[j][j] == Tabuleiro.DESCONHECIDO:
                    pos_vaziadp.append((j,j))
                #diagonal secundária
                totais[3] += self.matriz[j][2-j]
                if self.matriz[j][2-j] == Tabuleiro.DESCONHECIDO:
                    pos_vaziads.append((j,2-j))
            
            #verifica linha
            if len(pos_vaziah) == 1 and totais[0] == 2:
                return pos_vaziah[0]
            elif len(pos_vaziah) == 1 and totais[0] == 8:
                return pos_vaziah[0]
            
            #verifica coluna
            if len(pos_vaziav) == 1 and totais[1] == 2:
                return pos_vaziav[0]
            elif len(pos_vaziav) == 1 and totais[1] == 8:
                return pos_vaziav[0]
            
            #verifica diagonal principal
            if len(pos_vaziadp) == 1 and totais[2] == 2:
                return pos_vaziadp[0]
            elif len(pos_vaziadp) == 1 and totais[2] == 8:
                return pos_vaziadp[0]
            
            #verifica diagonal secundária
            if len(pos_vaziads) == 1 and totais[3] == 2:
                return pos_vaziads[0]
            elif len(pos_vaziads) == 1 and totais[3] == 8:
                return pos_vaziads[0]     
            
        #R2
        if self.matriz[0][1] == Tabuleiro.JOGADOR_0 and self.matriz[1][0] == Tabuleiro.JOGADOR_0:
            if self.matriz[0][0] == Tabuleiro.DESCONHECIDO:
                return (0,0)
            
        elif self.matriz[1][0] == Tabuleiro.JOGADOR_0 and self.matriz[2][1] == Tabuleiro.JOGADOR_0:
            if self.matriz[2][0] == Tabuleiro.DESCONHECIDO:
                return (2,0)
            
        elif self.matriz[2][1] == Tabuleiro.JOGADOR_0 and self.matriz[1][2] == Tabuleiro.JOGADOR_0:
            if self.matriz[2][0] == Tabuleiro.DESCONHECIDO:
                return (2,2)
            
        elif self.matriz[1][2] == Tabuleiro.JOGADOR_0 and self.matriz[0][1] == Tabuleiro.JOGADOR_0:
            if self.matriz[0][2] == Tabuleiro.DESCONHECIDO:
                return (0,2)

        #R3
        if self.matriz[1][1] == Tabuleiro.DESCONHECIDO:
            return (1,1)
        
        #R4
        if self.matriz[0][0] == Tabuleiro.JOGADOR_X and self.matriz[2][2] == Tabuleiro.DESCONHECIDO:
            return (2,2)
        elif self.matriz[0][2] == Tabuleiro.JOGADOR_X and self.matriz[2][0] == Tabuleiro.DESCONHECIDO:
            return (2,0)
        elif self.matriz[2][0] == Tabuleiro.JOGADOR_X and self.matriz[0][2] == Tabuleiro.DESCONHECIDO:
            return (0,2)
        elif self.matriz[2][2] == Tabuleiro.JOGADOR_X and self.matriz[0][0] == Tabuleiro.DESCONHECIDO:
            return (0,0)
        
        #R5
        if self.matriz[0][0] == Tabuleiro.DESCONHECIDO:
            return (0,0)
        elif self.matriz[0][2] == Tabuleiro.DESCONHECIDO:
            return (0,2)
        elif self.matriz[2][0] == Tabuleiro.DESCONHECIDO:
            return (2,0)
        elif self.matriz[2][2] == Tabuleiro.DESCONHECIDO:
            return (2,2)

        #R6
        lista = []
        for l in range(0,3):
            for c in range(0,3):
                if self.matriz[l][c] == Tabuleiro.DESCONHECIDO:
                    lista.append((l, c))

        if(len(lista) > 0):
            p = randint(0, len(lista)-1)
            return lista[p]
        else:
           return None