import pygame
import Piece
import Box

pygame.init()

# Define constants
WIDTH, HEIGHT = 600, 600 
ROWS, COLS = 8, 8 
BOARD = []
SQUARE_SIZE = WIDTH // COLS  

# Colors
WHITE = (255, 255, 255)
BLACK = (105, 105, 105)

# Create the window
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Chess Board")

def initialize_board():
    global BOARD
    BOARD = [[] for _ in range(ROWS)]  # Initialize the board as a list of lists
            
    for row in range(ROWS):
        for col in range(COLS):
            color = WHITE if (row + col) % 2 == 0 else BLACK
            
            if row == 1:  # Black pawns
                box = Box.Box(color,Piece.Piece("pawn", BLACK, "P"))
            elif row == 6:  # White pawns
                box = Box.Box(color,Piece.Piece("pawn", WHITE, "P"))
            elif row == 0:  # Black major pieces
                if col in [0, 7]:
                    box = Box.Box(color,Piece.Piece("rook", BLACK, "R"))
                elif col in [1, 6]:
                    box = Box.Box(color,Piece.Piece("knight", BLACK, "K"))
                elif col in [2, 5]:
                    box = Box.Box(color,Piece.Piece("bishop", BLACK, "B"))
                elif col == 3:
                    box = Box.Box(color,Piece.Piece("queen", BLACK, "Q"))
                elif col == 4:
                    box = Box.Box(color,Piece.Piece("king", BLACK, "Ki"))
            elif row == 7:  # White major pieces
                if col in [0, 7]:
                    box = Box.Box(color,Piece.Piece("rook", WHITE, "R"))
                elif col in [1, 6]:
                    box = Box.Box(color,Piece.Piece("knight", WHITE, "K"))
                elif col in [2, 5]:
                    box = Box.Box(color,Piece.Piece("bishop", WHITE, "B"))
                elif col == 3:
                    box = Box.Box(color,Piece.Piece("queen", WHITE, "Q"))
                elif col == 4:
                    box = Box.Box(color,Piece.Piece("king", WHITE, "Ki"))
            else:
                box = Box.Box(color,None)  # Empty square
            BOARD[row].append(box)  # Append the box to the current row
            # print(BOARD)


def is_path_clear(source_position, dest_position):
   
    source_row, source_col = source_position
    dest_row, dest_col = dest_position

    row_step = 0 if source_row == dest_row else (1 if dest_row > source_row else -1)
    col_step = 0 if source_col == dest_col else (1 if dest_col > source_col else -1)

    current_row, current_col = source_row + row_step, source_col + col_step
    while (current_row, current_col) != (dest_row, dest_col):
        if BOARD[current_row][current_col].piece is not None:  # Path is blocked
            return False
        current_row += row_step
        current_col += col_step

    return True  # Path is clear


def check_permission(piece, source_position, dest_position):
    if piece is None:
        print("No piece to move")
        return False  # No piece to move

    source_row, source_col = source_position
    dest_row, dest_col = dest_position

    print(f"Checking move for {piece.name} from {source_position} to {dest_position}")

    # Pawn movement logic
    if piece.name == "pawn":
        print(piece.color)
        direction = 1 if piece.color == WHITE else -1  # White pawns move up, Black pawns move down
        
        if dest_col == source_col:  # Moving forward
            if dest_row == source_row - direction and BOARD[dest_row][dest_col].piece is None:
                print("Pawn moving forward one step")
                return True
            # Allow two-step move from starting position
            if (source_row == 1 and piece.color == BLACK or source_row == 6 and piece.color == WHITE) and \
               dest_row == source_row + 2 * direction and BOARD[dest_row][dest_col].piece is None:
                print("Pawn moving forward two steps")
                return True
        elif abs(dest_col - source_col) == 1 and dest_row == source_row + direction:  # Capturing diagonally
            if BOARD[dest_row][dest_col].piece is not None and BOARD[dest_row][dest_col].piece.color != piece.color:
                print("Pawn capturing diagonally")
                return True
        print("Invalid pawn move")
        return False

    # Rook movement logic
    elif piece.name == "rook":
        if source_row == dest_row or source_col == dest_col:  # Moving in a straight line
            # Check if the path is clear
            if is_path_clear(source_position, dest_position):
                return True

    # Knight movement logic
    elif piece.name == "knight":
        if (abs(dest_row - source_row), abs(dest_col - source_col)) in [(2, 1), (1, 2)]:  # L-shaped moves
            return True

    # Bishop movement logic
    elif piece.name == "bishop":
        if abs(dest_row - source_row) == abs(dest_col - source_col):  # Moving diagonally
            # Check if the path is clear
            if is_path_clear(source_position, dest_position):
                return True

    # Queen movement logic
    elif piece.name == "queen":
        if source_row == dest_row or source_col == dest_col or abs(dest_row - source_row) == abs(dest_col - source_col):
            # Check if the path is clear
            if is_path_clear(source_position, dest_position):
                return True

    # King movement logic
    elif piece.name == "king":
        if abs(dest_row - source_row) <= 1 and abs(dest_col - source_col) <= 1:  # Moving one square in any direction
            return True

    return False  # If no valid move is found



def move_piece(start_row, start_col, end_row, end_col):
    # Get the piece from the starting box
    piece = BOARD[start_row][start_col].piece

    if (check_permission(piece , (start_row , start_col) , (end_row , end_col) )) :
        # Move the piece to the destination box
        BOARD[end_row][end_col].piece = piece

        # Remove the piece from the starting box
        BOARD[start_row][start_col].piece = None
        print(f"Moved piece from ({start_row}, {start_col}) to ({end_row}, {end_col})")
        print(f"Piece at destination: {BOARD[end_row][end_col].piece}")  # Debugging

    else :
        print("invalid move")


def draw_board():
    font = pygame.font.Font(None, 36)  # Initialize a font with size 36
    for row in range(ROWS):
        for col in range(COLS):
            # Draw the rectangle (box)
            pygame.draw.rect(screen, BOARD[row][col].color, (col * SQUARE_SIZE, row * SQUARE_SIZE, SQUARE_SIZE, SQUARE_SIZE))
            
            # Draw the piece symbol if there is a piece
            piece = BOARD[row][col].piece  # Assuming Box.Box has a 'piece' attribute
            if piece is not None:
                text = font.render(piece.symbol, True, (0, 0, 0))  # Render the piece symbol in black
                text_rect = text.get_rect(center=(col * SQUARE_SIZE + SQUARE_SIZE // 2, row * SQUARE_SIZE + SQUARE_SIZE // 2))
                screen.blit(text, text_rect)

# Main loop
running = True
initialize_board()
selected_box = None  # Initially, no box is selected

while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
        # Detect mouse click
        if event.type == pygame.MOUSEBUTTONDOWN and event.button == 1 :
            mouse_pos = pygame.mouse.get_pos()  # Get mouse position
            col = mouse_pos[0] // SQUARE_SIZE  # Calculate column
            row = mouse_pos[1] // SQUARE_SIZE  # Calculate row

            # Print the clicked box's row and column
            print(f"Box clicked: Row {row}, Column {col}")

            if selected_box is None:
                selected_box = (row, col)  # Store the selected box
                BOARD[row][col].color = (255, 255, 0)  # Highlight the box in yellow
            else:
                # If a box is already selected, call move_piece
                start_row, start_col = selected_box
                move_piece(start_row, start_col, row, col)

                # Reset the color of the previously selected box
                BOARD[start_row][start_col].color = WHITE if (start_row + start_col) % 2 == 0 else BLACK

                # Reset the selected box
                selected_box = None    
    
    draw_board()
    pygame.display.flip()

pygame.quit()
