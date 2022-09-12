# SortingVisualization
Sort ALgorithms Visualized with SDL2.


## Demo

### Merge sort
<p align="center">
  <img src= "demo/merge-sort.gif" />
</p>

### Bubble sort
<p align="center">
  <img src= "demo/bubble-sort.gif" />
</p>

### Selection sort
<p align="center">
  <img src= "demo/selection-sort.gif" />
</p>

### Insertion sort
<p align="center">
  <img src= "demo/insertion-sort.gif" />
</p>

### Quick sort
<p align="center">
  <img src= "demo/quick-sort.gif" />
</p>

### Heap sort
<p align="center">
  <img src= "demo/heap-sort.gif" />
</p>

### Main minu 
<p align="center">
  <img src= "demo/tutorial.gif" />
</p>



## How to run

### On Linux :

* Install cmake and sdl2.
```bash
sudo apt Install cmake libsdl2-dev
```

* Install sdl2-image 
```bash 
sudo apt install libsdl2-image-dev
```

* Install sdl2-ttf 
```bash 
sudo apt-get install libsdl2-ttf-dev
```

<br/>

* Clone the repo 
```bash 
git clone https://github.com/mohammed0xff/SortingVisualization
```

* Make n Run

```bash
cd SortingVisualization/SortingVisualization
```
```bash
cmake . && make 
```
```bash
./sortVisualizer 
```

<br/>

### On Windows : 

* Open `SortingVisualization.sln` file
* Follow [lazy foo](https://lazyfoo.net/tutorials/SDL/01_hello_SDL/windows/msvc2019/index.php) guide to set up SDL2 on Visual Studio.
* Press `F5` to build and run the program.



## Contribution 
#### 1. Drive from `SortVisualizer` class overriding the `sort` function, adding pointers and main sort functions.
```cpp  
namespace Visualizer {

    class SelectionSortVisulaizer : public SortVisualizer
    {
    public:
        SelectionSortVisulaizer(SDL_Renderer* renderer);
	      ~SelectionSortVisulaizer();

        void sort() override;

    private:
        void addPointers() override;
	      void selectionSort();

        // pointers used for accessing the array
        int idxOnePtr;
        int idxTwoPtr;
        int min_idxPtr;

    };

};

```

#### 2. Implement your sort function.
* place the rendering function `render()` wherever there is a change to the array.
* `incArrayAccess()`, `incComparisons()` to count comparisons and array accesses over the array.
 
```cpp  
void SelectionSortVisulaizer::sort()
{
    selectionSort();
}

void SelectionSortVisulaizer::selectionSort()
{
    for (idxOnePtr = startElement; idxOnePtr < endElement; idxOnePtr++)
    {
        min_idxPtr = idxOnePtr;
        for (idxTwoPtr = idxOnePtr + 1; idxTwoPtr < endElement; idxTwoPtr++) {

            if (m_arr[idxTwoPtr] < m_arr[min_idxPtr])
                min_idxPtr = idxTwoPtr;
            incArrayAccess(2);
            incComparisons(3);
            render();
        }
        std::swap(m_arr[min_idxPtr], m_arr[idxOnePtr]);
        incArrayAccess(2);
    }
}

```
#### 3. add the pointers refrences to `m_pointers` array with a chosen color.
```cpp
void SelectionSortVisulaizer::addPointers() {
    m_pointers.push_back(std::pair<int&, Color>(idxOnePtr, GREEN));
    m_pointers.push_back(std::pair<int&, Color>(idxTwoPtr, GREEN));
    m_pointers.push_back(std::pair<int&, Color>(min_idxPtr, BLUE));
}
```

#### 4. Edit `Mianminu` class as well as the `SortVisualizer.psd` photoshop file to add your new sort algorithm to the main minu. <br/> if you can't do it just ask me and i will do it for you :D.
#### 5. Any contrubutions are appreaciated, you can have as much fun as you want with this project <3.


## To Do : 
- [ ] Implement a `TextManager` class to seperate text rendering management from `SortVisualizer` class.
- [ ] Implement an `EventHandler` class with ``` std::unordered_map<T, callback> ``` where `T` is an event.
- [ ] Make text look prettier.
- [ ] Add sound.

