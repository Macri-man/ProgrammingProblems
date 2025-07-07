import sys

def classify_day_or_night():
    total_brightness = 0
    pixel_count = 0

    for line in sys.stdin:
        line = line.strip()
        if not line:
            continue
        pixels = line.split()
        for pixel in pixels:
            try:
                b, g, r = map(int, pixel.split(','))
                brightness = (r + g + b) / 3
                total_brightness += brightness
                pixel_count += 1
            except:
                continue  # Ignore malformed pixels

    avg_brightness = total_brightness / pixel_count if pixel_count else 0

    # Empirical threshold: tweakable based on data
    print('day' if avg_brightness > 100 else 'night')

if __name__ == '__main__':
    classify_day_or_night()
