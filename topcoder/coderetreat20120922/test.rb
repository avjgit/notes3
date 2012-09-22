class Game
    def initialize
        @board = Array.new(3) {Array.new(3) {Array.new(3) {nil}}}
    end
    def set (value, addressX, addressY, addressZ)
        @board[addressX][addressY][addressZ] = value
    end
    def is_board_full
        3.times do |row|
            3.times do |column|
                if @board[row][column].nil?
                    return false
                end
            end
        end
        return true
    end
    def is_column_full
        3.times do |slice|
            3.times do |column|
                column_full = true
                first_element = @board[0][column][slice]
                3.times do |row|
                    if @board[row][column][slice] != first_element
                        column_full = false
                    end
                end
                if column_full
                    return true
                end
            end
        end
        return false
    end
end

def print_test_result(passed, description)
    result = "failed!"

    if passed
        result = "passed"
    end

    p (result + ' ' + description)
end

g = Game.new()
p g.inspect

print_test_result(g.is_column_full, 'one of columns is taken - with all columns full')
# g.set(nil, 0 , 0 , 0)

g.set(nil, 0, 0, 0)
# print_test_result(!g.is_board_full, 'board with free cell is not full')
# #p g.inspect
print_test_result(g.is_column_full, 'one of columns is taken - with 2nd and 3rd full (1st free)')

# g.set(nil,1,2)
# g.set(nil,2,1)
# print_test_result(g.is_column_full, 'one of columns is taken - every column has nil')

############### session 4

 class Game
    def play
        win = false
        i = 0
        while not win do
            puts "playing"
            win = ((i += 1) == 4)
        end
    end
end

# game = Game.new();

# game.play
