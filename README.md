# Playlist do Momento

## Sobre o Projeto
**Projeto:** Playlist do Momento

**Problema que resolve:** Dificuldade das pessoas em escolher rapidamente uma playlist que combine com seu humor e o momento atual.

## Integrantes
| Nome | GitHub |
|------|--------|
| Anita Barbosa | @anitaobpuc |
| Ivan Henrique | @Iwanhrq |
| Miguel Moura | @miguelsrmoura12 |

## Arquitetura
```mermaid
graph LR
    subgraph Entrada [Entrada]
        A[Google Forms] -- "Humor, Clima e WhatsApp" --> B((Webhook n8n))
    end

    subgraph Processamento [Processamento]
        B --> C[Gemini IA]
        C -- "Análise de Humor + Clima" --> D[Spotify API]
        D -- "Busca de Playlist" --> E[Montar resposta]
    end

    subgraph Saida [Saida]
        E -- "Link da Playlist" --> F[WhatsApp]
        F --> G{Usuário Final}
    end


    style A fill:#4285F4,stroke:#333,color:#fff
    style C fill:#4285F4,stroke:#333,color:#fff
    style D fill:#1DB954,stroke:#333,color:#fff
    style F fill:#25D366,stroke:#333,color:#fff
