# -*- coding: utf-8 -*-

class Tabuleiro:
    DESCONHECIDO = 0
    JOGADOR_0 = 1
    JOGADOR_X = 4

    def __init__(self):
        self.matriz = [ [Tabuleiro.DESCONHECIDO, Tabuleiro.DESCONHECIDO, Tabuleiro.DESCONHECIDO], 
                        [Tabuleiro.DESCONHECIDO, Tabuleiro.DESCONHECIDO, Tabuleiro.DESCONHECIDO],
                        [Tabuleiro.DESCONHECIDO, Tabuleiro.DESCONHECIDO, Tabuleiro.DESCONHECIDO]]
       
        
    def tem_campeao(self):

        for i in range(3):
            totais = [0, 0, 0, 0]

            for j in range(3):
                totais[0] += self.matriz[i][j] #linhas
                totais[1] += self.matriz[j][i] #colunas
                totais[2] += self.matriz[j][j] #diagonal principal
                totais[3] += self.matriz[j][2-j] #diagonal secundária

                #verifica se a soma condiz com um vitorioso em algum caso
                if totais[0] == 3:
                    return Tabuleiro.JOGADOR_0
                elif totais[0] == 12:
                    return Tabuleiro.JOGADOR_X
                
                if totais[1] == 3:
                    return Tabuleiro.JOGADOR_0
                elif totais[1] == 12:
                    return Tabuleiro.JOGADOR_X
                
                if totais[2] == 3:
                    return Tabuleiro.JOGADOR_0
                elif totais[2] == 12:
                    return Tabuleiro.JOGADOR_X
                
                if totais[3] == 3:
                    return Tabuleiro.JOGADOR_0
                elif totais[3] == 12:
                    return Tabuleiro.JOGADOR_X


        return Tabuleiro.DESCONHECIDO
