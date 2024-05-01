#!/usr/bin/python3
import math

class TargetTracker:
    def __init__(self, cote_cible=100, range_capteurs=1024):
        self.cote_cible = cote_cible
        self.range_capteurs = range_capteurs

    def calculate_hit_position(self, pressure_sensor1, pressure_sensor2, pressure_sensor3, pressure_sensor4):
        # Coins de la cible
        # P1 P2
        # P3 P4
        # Origine en P3
        corner_x = [0, self.cote_cible, 0, self.cote_cible]
        corner_y = [self.cote_cible, self.cote_cible, 0, 0]

        # Plage de recherche pour les coordonnées x et y
        min_x = 0
        max_x = self.cote_cible
        min_y = 0
        max_y = self.cote_cible

        pressures = [pressure_sensor1/self.range_capteurs, pressure_sensor2/self.range_capteurs, pressure_sensor3/self.range_capteurs, pressure_sensor4/self.range_capteurs]

        def calculate_distance(x, y, corner_x, corner_y, pressures):
            total_distance = 0
            weighted_distance = 0
            for i in range(4):
                distance = math.sqrt((corner_x[i] - x)**2 + (corner_y[i] - y)**2)
                # On met tout au carré pour privilégier les distances composées
                weighted_distance = (distance * pressures[i])**2
                total_distance += weighted_distance
            return total_distance

        min_sum_distance = float('inf')
        best_x = 0
        best_y = 0

        # Recherche des coordonnées optimales
        for x in range(min_x, max_x + 1):
            for y in range(min_y, max_y + 1):
                sum_distance = calculate_distance(x, y, corner_x, corner_y, pressures)
                if sum_distance < min_sum_distance:
                    min_sum_distance = sum_distance
                    best_x = x
                    best_y = y

        return best_x, best_y

if __name__ == '__main__':
    # Exemple d'utilisation
    tracker = TargetTracker()
    x, y = tracker.calculate_hit_position(512, 512, 512, 512)
    print("Coordonnées optimales (x, y) où la balle a touché la cible : ({}, {})".format(x, y))
