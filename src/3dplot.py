import numpy as np
import matplotlib.pyplot as plt

def update_plot(x, y, z, ax):
    ax.clear()
    ax.scatter(x, y, z)
    ax.set_xlabel('X')
    ax.set_ylabel('Y')
    ax.set_zlabel('Z')
    ax.set_title('Live Plot')

    ax.set_xlim(0, 100)
    ax.set_ylim(0, 100)
    ax.set_zlim(0, 100)

    plt.draw()
    plt.pause(0.1)

def main():
    fig = plt.figure()
    ax = fig.add_subplot(111, projection='3d')
    
    x = []
    y = []
    z = []

    while True:
        # Generiere 10 zufällige Werte für x, y und z
        x = np.random.randint(0, 100, 10)
        y = np.random.randint(0, 100, 10)
        z = np.random.randint(0, 100, 10)

        update_plot(x, y, z, ax)

if __name__ == "__main__":
    main()
