import Control.Monad (mapM_)

height, width :: Int
height = 32
width  = 63

-- Set a row with 1's centered at y with given length
setCells :: Int -> Int -> [Char] -> [Char]
setCells y len =
  zipWith (\i c -> if i >= y - len `div` 2 && i <= y + len `div` 2 then '1' else c) [0..]

-- Replace row at index with new row
setRow :: Int -> [Char] -> [[Char]] -> [[Char]]
setRow idx newRow =
  zipWith (\i row -> if i == idx then newRow else row) [0..]

-- Draw upright triangle of height h at (x, y)
drawUp :: Int -> Int -> Int -> [[Char]] -> [[Char]]
drawUp 0 _ _ canvas = canvas
drawUp h x y canvas =
  let rowIndex = x + h - 1
      row = canvas !! rowIndex
      newRow = setCells y (2 * h - 1) row
      updatedCanvas = setRow rowIndex newRow canvas
  in drawUp (h - 1) x y updatedCanvas

-- Recursive Sierpinski draw
draw :: Int -> Int -> Int -> Int -> [[Char]] -> [[Char]]
draw 0 x y h canvas = drawUp h x y canvas
draw n x y h canvas =
  let h2 = h `div` 2
      top    = draw (n - 1) x y h2 canvas
      left   = draw (n - 1) (x + h2) (y - h2) h2 top
      right  = draw (n - 1) (x + h2) (y + h2) h2 left
  in right

-- Main program
main :: IO ()
main = do
  n <- readLn
  let empty = replicate height (replicate width '_')
      result = draw n 0 (width `div` 2) height empty
  mapM_ putStrLn result
