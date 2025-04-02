class Box:
    def __init__(self , color , piece):
        self.color = color
        self.piece = piece

    def place_piece(self, piece):
        self.piece = piece

    def remove_piece(self):
        self.piece = None       
