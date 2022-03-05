#ifndef RENDERER_SPA_HPP
#define RENDERER_SPA_HPP

#include "Renderer.hpp"
#include <iostream>

struct RendererSPA final : Renderer
{
    void drawMenu() const noexcept final;
    void askForName() const noexcept final;
    void errorUserExist() const noexcept final;
    void addUser(std::string_view user) const noexcept final;
    void askFrom() const noexcept final;
    void askFromUser(std::string_view user) const noexcept final;
    void errorUserNOTExist() const noexcept final;
    void askTo() const noexcept final;
    void askMessage() const noexcept final;
    void askMessageSent() const noexcept final;
    void askForNameUser() const noexcept final;
    void askBeginMessages() const noexcept final;
    void askNumberMessage(int nMess) const noexcept final;
    void askContent() const noexcept final;
    void askContentUser(std::string_view user) const noexcept final;
    void askEndMessages() const noexcept final;
    void askQuit() const noexcept final;
    void errorInvalidOpt() const noexcept final;
    void askWait4Key() const noexcept final;

private:
    // ALL IN STATIC TO DUPLICATE TO SPANISH EASY AND FAST.
    inline static constexpr auto k_rawMenu{R"(Porfavor, seleccione una opcion:
    1. Crear Usuario
    2. Enviar Mensaje
    3. Recibir todos los mensajes de un usuario
    4. Cambiar idioma
    5. Salir
)"};

    inline static constexpr auto k_askName{"Porfavor, ingrese un nombre:"};
    inline static constexpr auto k_errUserEx{"¡ERROR: El usuario ya existe!"};
    inline static constexpr auto k_user{"Usuario "};
    inline static constexpr auto k_added{" añadido!"};
    inline static constexpr auto k_from{"Desde: "};
    inline static constexpr auto k_errUserNOTEx{"ERROR: El usuario no existe!"};
    inline static constexpr auto k_to{"Para: "};
    inline static constexpr auto k_message{"Mensaje: "};
    inline static constexpr auto k_messageSent{"Mensaje enviado!"};
    inline static constexpr auto k_nameUser{"Ingrese el nombre del usuario del que quiere decibir todos los mensajes: "};
    inline static constexpr auto k_begMessages{"===== LISTA DE MENSAJES ====="};
    inline static constexpr auto k_content{"Contenido: "};
    inline static constexpr auto k_endMessages{"===== FIN LISTA DE MENSAJES ====="};
    inline static constexpr auto k_quit{"Saliendo!"};
    inline static constexpr auto k_errInvOpt{"La opcion seleccionada es invalida"};
    inline static constexpr auto k_wait4Key{"Pulse ENTER para continuar"};
};

#endif /* RENDERER_SPA_HPP */
