#include "SceneController.h"

SceneController* SceneController::instance;
SceneController* SceneController::get_instance(string _fileName)
{
    if (instance == nullptr) instance = new SceneController(_fileName);
    return instance;
}

void SceneController::menu()
{
    cout << "1: рух фігури" << endl;
    cout << "2: додати фігуру" << endl;
    cout << "3: видалити фігуру" << endl;
    cout << "4: клонувати фігуру" << endl;
    cout << "5: додати до композиту" << endl;
    cout << "6: змінити колір" << endl;
    cout << "7: деформація фігури" << endl;
    cout << "8: збереження до файлу" << endl;
    cout << "9: завантаження з файлу" << endl;
    cout << "ЛКМ: обрати фігуру" << endl;
    cout << "ESC: вихід з програми" << endl;
}

void SceneController::start()
{
    ofstream out(fileName);
    out << "";
    out.close();
    float move_coff = 0.1;
    int coll_idx = -1;
    Clock* keyboard_clock = new Clock;
    bool is_comp_in_vector = false;
    int counter = 0, figures_counter = 0;
    Rectangle* rect = new Rectangle(200, 100, Color::Cyan, 100, 100);
    Square* square = new Square(100, Color::Yellow, 500, 600);
    add_figure(rect);
    add_figure(square);
    cout << "Натисніть F1 щоб перейти до меню" << endl;
    bool f1IsPressed = false;
    //menu();
    Color main_color = Color(0, 0, 0);
    while (window->isOpen()) {
        if (Keyboard::isKeyPressed(Keyboard::F1) && f1IsPressed == false)
        {
            menu();
            f1IsPressed = true;
        }
        window->clear(main_color);
        for (int i = 0; i < figures.size(); i++) {
            figures[i]->draw(*window);
        }
        window->display();
        Event event;
        while (window->pollEvent(event)) {
            if (event.type == Event::Closed) {
                window->close();
            }
            if (Mouse::isButtonPressed(Mouse::Left)) {
                Vector2i mouse_pos = Mouse::getPosition(*window);
                Vector2f translated_pos = window->mapPixelToCoords(mouse_pos);
                for (int i = 0; i < figures.size(); i++)
                {
                    if (figures[i]->get_bounds().contains(translated_pos)) {
                        selected_figure = i;
                        figures[i]->set_selected(true);
                    }
                }
            }
            if (figures[selected_figure] != nullptr) {
                if (Keyboard::isKeyPressed(Keyboard::Num1)) {
                    if (figures[selected_figure]->get_selected()) {
                        figures[selected_figure]->move(window->getSize(), move_coff, 1000);
                        window->clear(main_color);
                        if (collision_check()) {
                            figures[selected_figure]->set_color(Color::Magenta);
                        }
                        for (int i = 0; i < figures.size(); i++)
                        {
                            figures[i]->draw(*window);
                        }
                        window->display();
                        keyboard_clock->restart();
                        while (keyboard_clock->getElapsedTime().asSeconds() < 1) {}
                    }
                    else {
                        cout << "Вы должны выбрать фигуру!" << endl;
                        keyboard_clock->restart();
                        while (keyboard_clock->getElapsedTime().asSeconds() < 1) {}
                        break;
                    }
                }
                if (Keyboard::isKeyPressed(Keyboard::Num3)) {
                    if (figures[selected_figure]->get_selected())
                    {
                        if (figures.size() > 1)
                        {
                            figures[selected_figure]->remove(window);
                            figures.erase(figures.begin() + selected_figure);
                            selected_figure--;
                            if (selected_figure < 0)
                            {
                                selected_figure = figures.size() - 1;
                            }
                            for (int i = 0; i < figures.size(); i++) {
                                if (figures[i]->get_figure_type() == "composite") counter++;
                            }
                            if (counter == 0) {
                                is_comp_in_vector = false;
                            }
                            counter = 0;
                        }
                        else {
                            cout << "Повинен бути хоча б один елемент" << endl;
                        }
                        keyboard_clock->restart();
                        while (keyboard_clock->getElapsedTime().asSeconds() < 1) {}
                    }
                    else {
                        cout << "Оберіть фігуру!" << endl;
                        keyboard_clock->restart();
                        while (keyboard_clock->getElapsedTime().asSeconds() < 1) {}
                        break;
                    }
                }
                if (Keyboard::isKeyPressed(Keyboard::Num4)) {
                    if (figures[selected_figure]->get_selected())
                    {
                        add_figure(figures[selected_figure]->clone());
                        window->clear(main_color);
                        for (int i = 0; i < figures.size(); i++)
                        {
                            figures[i]->draw(*window);
                        }
                        window->display();
                        keyboard_clock->restart();
                        while (keyboard_clock->getElapsedTime().asSeconds() < 1) {}
                    }
                    else {
                        cout << "Оберіть фігуру!" << endl;
                        break;
                    }
                }
                if (Keyboard::isKeyPressed(Keyboard::Num5)) {
                    if (figures[selected_figure]->get_selected()) {
                        Composite* comp = nullptr;
                        if (!is_comp_in_vector) {
                            comp = new Composite(500, 500);
                            figures.push_back(comp);
                            is_comp_in_vector = true;
                        }
                        else {
                            cout << "Оберіть композит" << endl;
                            cout << "-1 - новий" << endl;
                            int choice;
                            for (int i = 0; i < figures.size(); i++) {
                                if (figures[i]->get_figure_type() == "composite") {
                                    comp = (Composite*)figures[i];
                                    cout << i << " (" << comp->get_count() << " фігур)" << endl;
                                }
                            }
                            cin >> choice;
                            if (choice == -1) {
                                comp = new Composite(500, 200);
                                figures.push_back(comp);
                            }
                            else if (choice < figures.size() && figures[choice]->get_figure_type() == "composite") {
                                comp = (Composite*)figures[choice];
                            }
                        }
                        Figure* fig = figures[selected_figure]->clone();
                        
                        fig->set_position(comp->get_x(), comp->get_y());
                        comp->add(fig);


                        figures[selected_figure]->remove(window);
                        figures.erase(figures.begin() + selected_figure);


                        keyboard_clock->restart();
                        while (keyboard_clock->getElapsedTime().asSeconds() < 1) {}
                    }
                    else {
                        cout << "Оберіть фігуру!" << endl;
                        keyboard_clock->restart();
                        while (keyboard_clock->getElapsedTime().asSeconds() < 1) {}
                        break;
                    }
                }
                if (Keyboard::isKeyPressed(Keyboard::Num6)) {
                    if (figures[selected_figure]->get_selected()) {
                        int choice;
                        cout << "1 - blue, 2 - yellow, 3 - red, 4 - green, 5 - magenta" << endl;
                        cout << "Оберіть колір: " << endl;
                        cin >> choice;
                        Color c = colors[choice - 1];
                        figures[selected_figure]->set_color(c);
                        window->clear(main_color);
                        for (int i = 0; i < figures.size(); i++)
                        {
                            figures[i]->draw(*window);
                        }
                        window->display();
                        keyboard_clock->restart();
                        while (keyboard_clock->getElapsedTime().asSeconds() < 1) {}
                    }
                    else {
                        cout << "Ви повинні обрати фігуру!" << endl;
                        keyboard_clock->restart();
                        while (keyboard_clock->getElapsedTime().asSeconds() < 1) {}
                        break;
                    }
                }
                if (Keyboard::isKeyPressed(Keyboard::Num7)) {
                    if (figures[selected_figure]->get_selected()) {
                        figures[selected_figure]->transform();
                        window->clear(main_color);
                        for (int i = 0; i < figures.size(); i++)
                        {
                            figures[i]->draw(*window);
                        }
                        window->display();
                        keyboard_clock->restart();
                        while (keyboard_clock->getElapsedTime().asSeconds() < 1) {}
                    }
                    else {
                        cout << "Оберіть фігуру!" << endl;
                        keyboard_clock->restart();
                        while (keyboard_clock->getElapsedTime().asSeconds() < 1) {}
                        break;
                    }
                }
                if (Keyboard::isKeyPressed(Keyboard::Num8)) {
                    int before = 0;
                    figures_counter = figures.size();
                    for (int i = 0; i < figures.size(); i++) {
                        if (figures[i]->get_figure_type() == "rectangle") {
                            RectangleUtils utils;
                            before = utils.load_state((Rectangle*)figures[i], before);
                        }
                        else if (figures[i]->get_figure_type() == "square") {
                            SquareUtils utils;
                            before = utils.load_state((Square*)figures[i], before);
                        }
                        else if (figures[i]->get_figure_type() == "composite") {
                            CompositeUtils utils;
                            before = utils.load_state((Composite*)figures[i], before);
                        }
                    }
                    keyboard_clock->restart();
                    while (keyboard_clock->getElapsedTime().asSeconds() < 1) {}
                }
                if (Keyboard::isKeyPressed(Keyboard::Num9)) {
                    figures.erase(figures.begin() + figures_counter, figures.begin() + figures.size());
                    counter = 0;
                    for (int i = 0; i < figures.size(); i++) {
                        if (figures[i]->get_figure_type() == "rectangle") {
                            RectangleUtils utils;
                            utils.save_state((Rectangle*)figures[i], counter);
                        }
                        else if (figures[i]->get_figure_type() == "square") {
                            SquareUtils utils;
                            utils.save_state((Square*)figures[i], counter);
                        }
                        else if (figures[i]->get_figure_type() == "composite") {
                            CompositeUtils utils;
                            utils.save_state((Composite*)figures[i], counter);
                            Composite* comp = (Composite*)figures[i];
                            if (comp->get_count() == 0) {
                                figures[i]->remove(window);
                                figures.erase(figures.begin() + i);
                            }
                        }
                        if (i < figures.size()) {
                            counter += figures[i]->get_bytes_written();
                        }
                    }
                    if (figures.size() > 0) {
                        selected_figure = 0;
                    }
                    window->clear(main_color);
                    for (int i = 0; i < figures.size(); i++)
                    {
                        figures[i]->draw(*window);
                    }
                    window->display();
                    keyboard_clock->restart();
                    while (keyboard_clock->getElapsedTime().asSeconds() < 1) {}
                }
            }
            if (Keyboard::isKeyPressed(Keyboard::Num2)) {
                Square* square;
                Rectangle* rect;
                int width, height, x = 0, y = 0, color, shape;
                cout << "Введіть координати: ";
                cin >> x >> y;
                cout << "Введіть тип фігури: " << endl;
                cout << "1 - прямокутник" << endl;
                cout << "2 - квадрат" << endl;
                cin >> shape;
                cout << "Введіть колір: " << endl;
                cout << "1 - синій, 2 - желтый, 3 - червоний, 4 - зеленый, 5 - блакитний" << endl;
                cin >> color;
                cout << "Введіть ширину: ";
                cin >> width;
                switch (shape) {
                case 1:
                    cout << "Введіть висоту: ";
                    cin >> height;
                    rect = new Rectangle(width, height, colors[color - 1], x, y);
                    add_figure(rect);
                    break;
                case 2:
                    square = new Square(width, colors[color - 1], x, y);
                    add_figure(square);
                    break;
                }
                for (int i = 0; i < figures.size(); i++)
                {
                    figures[i]->draw(*window);
                }
                window->display();
                keyboard_clock->restart();
                while (keyboard_clock->getElapsedTime().asSeconds() < 1) {}
            }
            if (Keyboard::isKeyPressed(Keyboard::Escape)) { exit(0); }
        }
    }
}
